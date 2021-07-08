// Route Between Nodes

#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector <Node*> ();
    }
    Node(int val) : val(val) {
        neighbors = vector <Node*> ();
    }

    Node(int val, vector <Node*> neighbors) : val(val), neighbors(neighbors) {}

    void insertNode(Node* node) {
        neighbors.push_back(node);
    }

    void printGraph() {
        for (const auto& neighbor: neighbors) {
            cout << val << "->" << neighbor->val << endl;
            for (const auto& nextNeighbor: neighbor->neighbors) {
                cout << neighbor->val << "->" << nextNeighbor->val << endl;
            }
        }
    }
};

// Depth First Search
bool routeNodes (Node* s, Node* e) {
    for (const auto& neighbor: s->neighbors) {
        if (neighbor == e) {
            return true;
        }
        for (const auto& nextNeighbor: neighbor->neighbors) {
            if (nextNeighbor == e) {
                return true;
            }
        }
    }
    return false;
}

// Using a Queue for Breadth First Search
bool routeNodes2(Node* x, Node* y) {
    map <Node*, bool> visited;
    queue <Node* > q;
    q.push(x);
    while (!q.empty()) {
        Node* top = q.front();
        q.pop();
        cout << top->val << endl;
        if (top == y) {
            return true;
        }
        for (const auto& node : top->neighbors) {
            if (!visited[node]) {
                visited[node] = true;
                q.push(node);
            }
        }
    }
    return false;
}

int main(){
    Node* head = new Node(1);
    Node* y = new Node(505);
    Node* x;
    for (int i = 2; i < 10; i++) {
        x = new Node(i);
        head->insertNode(x);
        x->insertNode(new Node(i+1));
    }
    x->insertNode(y);
    // head->printGraph();
    cout << routeNodes2(head, y) << endl;
    return 0;
}