// Build Order
// Still need to look over solution 1


#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// For Implementation 1
// struct Node {
//     char val;
//     vector <Node*> d; // d for dependencies

//     Node() : val(' '), d(vector <Node*> ()) {}
//     Node (char val) : val(val), d(vector <Node*> ()) {}
//     void insertNode(Node* n) {
//         d.push_back(n);
//     }
// };

// For Solution #2 from book: utilizes topological sort
struct Node {
    char val;
    char state; // 'c' , 'p' , 'b' for complete, partial, blank
    vector <Node*> d; // d for dependencies

    Node() : val(' '), state('b'), d(vector <Node*> ()) {}
    Node (char val) : val(val), state('b'), d(vector <Node*> ()) {}
    void insertNode(Node* n) {
        d.push_back(n);
    }
};


struct Graph {
    vector <Node*> nodes;
    Graph () : nodes(vector<Node*> ()) {}
    
    void insertNode(Node* n) {
        for (const auto& node: nodes) {
            if (node->val == n->val ){
                return;
            }
        }
        nodes.push_back(n);
    }
};


void getD(Node* n, vector<Node*>& built) {
    if (n == nullptr) {
        cout << "NO BUILD ORDER EXISTS" << endl;
        return;
    }
    bool good = false;
    for (const auto& noded: n->d) {
        good = false;
        for (const auto& nodeb: built) {
            if (nodeb->val == noded->val) {
                good = true;
                break;
            }
        }
        if (!good) {
            getD(noded, built);
        }
    }
    if (good) {
        bool duplicate = false;
        for (const auto& nodeb: built) {
            if (n->val == nodeb->val) {
                duplicate = true;
            }
        }
        if (!duplicate) {
            built.push_back(n);
        }
    }

}

void printGraph(vector <Node*> built) {
    for (const auto& node: built) {
        cout << node->val << ", ";
    }
}

// Works if the build order does exist but can't detect if does not exist
// Would need to add states to each of the nodes for COMPLETE, PARTIAL, BLANK
// Utilizes a DFS approach
// ! This algorithm is incorrect
vector <Node*> buildOrder(vector<Node*> projects, vector<pair<Node*, Node*>> dependencies) {
    Graph* g = new Graph();
    vector <Node*> built = projects;
    for (const auto& projPair: dependencies) {
        g->insertNode(projPair.second);
        projPair.second->insertNode(projPair.first);

        // Essentially find if dependency needed then delete, leaving vector with nodes that don't need dependency
        for (int i = 0; i < built.size(); i++) {
            if (built[i]->val == projPair.second->val) {
                built.erase(built.begin() + i);
            }
        }
    }

    while (built.size() < projects.size()) {
            for (const auto& node: g->nodes) {
                getD(node, built);
            }
    }
    return built;
}

bool getD2(Node* n, vector<Node*> & built){
    if (n->state == 'p') {return false;} // cycle detected
    if (n->state == 'b') {
        n->state = 'p';
        vector<Node*> children = n->d;
        for (Node* child: children) {
            if (!getD2(child, built)) {
                return false;
            }
        }
        n->state = 'c';
        built.push_back(n);
    }
    return true;
}

// ! This algorithm works for the problem
// Solution comes from topological sort that looks to use DFS to get all dependencies and then
// add nodes to the buildOrder as they are marked complete
// Does better than previous algorithm since we are able to detect whether or not there is a loop
// Loop detected if you run into a node that is marked partial already
// Why does this work? Theoretically, if marked partial then the graph should traverse downwards to get the dependencies, but if we see it again, then that means that the dependencies
// would also require that certain project that has already been marked partial, creating an infinite loop
vector <Node*> buildOrder2(vector<Node*> projects, vector<pair<Node*, Node*>> dependencies) {
    Graph* g = new Graph();
    vector <Node*> built = vector <Node*> ();
    for (const auto& projPair: dependencies) {
        g->insertNode(projPair.second);
        projPair.second->insertNode(projPair.first);
    }


    for (Node* project: projects) {
        if (project->state == 'b') {
            if (!getD2(project, built)) {
                cout << "THERE IS NO BUILD ORDER" << endl;
                return {}; // exemplifies NULL
            }
        }
    }
    return built;
}

int main() {
    vector<Node*> projects;
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');
    // Node* g = new Node('g');
    projects.push_back(a);
    projects.push_back(b);
    projects.push_back(c);
    projects.push_back(d);
    projects.push_back(e);
    projects.push_back(f);
    // projects.push_back(new Node('g'));

    vector<pair<Node*, Node*>> dependencies;
    dependencies.push_back(make_pair(a,d));
    dependencies.push_back(make_pair(f,b));
    dependencies.push_back(make_pair(b,d));
    dependencies.push_back(make_pair(f,a));
    dependencies.push_back(make_pair(d,c));
    // dependencies.push_back(make_pair(g, a));
    // dependencies.push_back(make_pair(a, g));

    printGraph(buildOrder2(projects, dependencies));
    return 0;
}