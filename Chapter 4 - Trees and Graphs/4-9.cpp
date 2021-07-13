// BST Sequences
// https://medium.com/@jackwootton/binary-search-tree-sequences-53163b1f374a

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    int bf;
    Node* left;
    Node* right;
    Node* parent;
    Node () : val(0), bf(0), left(nullptr), right(nullptr) {}
    Node (int val) : val(val), bf(0), left(nullptr), right(nullptr) {}
};

Node* minimalTree(vector <int> arr, int low, int high) {
    if (arr.size() == 0) {return nullptr;}
    if (low > high) {return nullptr;}

    int mid = (low + high) / 2;
    Node* node = new Node(arr[mid]);
    Node* temp  = minimalTree(arr, low, mid - 1);
    if (temp != nullptr) {
        node->left = temp;
        temp->parent = node;
    }

    Node* temp2 = minimalTree(arr, mid + 1, high);
    if (temp2 != nullptr) {
        node->right = temp2;
        temp2->parent = node;
    }

    return node;
} 

// My idea is that we can think of each of the nodes as a "root" after we delete its parent
// Also, we know that the root is always the first node
// ! I could not successfully implement the recursion and weaving of the nodes
vector <Node*> BSTSequences(Node* n) {
    queue <Node*> q;
    q.push(n);
    vector <Node*> order;

    while (!q.empty()) {
        Node* x = q.front();
        q.pop();
        if (x->parent == nullptr) {
            order.push_back(x);
        }
        if (x->left != nullptr) {
            x->left->parent = nullptr;
            q.push(x->left);
        }
        if (x->right != nullptr) {
            x->right->parent = nullptr;
            q.push(x->right);
        }
    }
    return order;
}
void addAll(vector<Node*> toAdd, vector <Node*> & vec) {
    for (const auto& node: toAdd) {
        vec.push_back(node);
    }
}

void addAll(vector<vector<Node*>> toAdd, vector<vector<Node*>> & vec) {
    for (const auto& nodes: toAdd) {
        vector<Node*> temp = vector<Node*>();
        for (const auto& node: nodes) {
            temp.push_back(node);
        }
        vec.push_back(temp);
    }
}

void print2Dlist(vector <vector<Node*>> arr) {
    cout << "{" << endl;
    for (const auto& nodes: arr) {
        cout << "   {";
        for (const auto& node: nodes) {
            cout << node->val << ", ";
        }
        cout << "}" << endl;
    }
    cout << "}" << endl;
}

// BELOW IS SOLUTION WRITTEN FROM THE BOOK
void weaveLists(vector<Node*> & first, vector<Node*> & second, vector<vector<Node*>> & results, vector<Node*> & prefix) {
    // If one list is empty then take the stored values of prefix and add to result
    // This is the summation of the lists at the very end
    if(first.size() == 0 || second.size() == 0) {
        vector<Node*> result = vector<Node*>();
        addAll(prefix, result);
        addAll(first, result);
        addAll(second, result);
        results.push_back(result);
        return;

    }
    
    // Takes a node from the first array and puts it into prefix
    Node* headFirst = first[0];
    first.erase(first.begin());
    prefix.push_back(headFirst);

    // calls prefix
    weaveLists(first, second, results, prefix);
    prefix.pop_back();

    // puts the first element back to the first array
    first.insert(first.begin(), headFirst);

    // Takes the first node from the second array and puts it into prefix
    Node* headSecond = second[0];
    second.erase(second.begin());
    prefix.push_back(headSecond);

    // calls prefix
    weaveLists(first, second, results, prefix);

    // puts the first element back to the second array
    prefix.pop_back();
    second.insert(second.begin(), headSecond);

}

vector<vector<Node*>> allSequences(Node* node) {
    vector <vector< Node*>> result = vector<vector<Node*>>();

    // if node is nullptr then just add nothing
    if (node == nullptr) {
        result.push_back(vector<Node*>());
        return result;
    }
    vector<Node*> prefix = vector<Node*>();

    // This will be the first element of either the left or right subtree
    prefix.push_back(node);

    //Recursively call the left and right subtrees again
    // This will get the entire left and right subtrees of the root
    vector<vector<Node*>> leftSeq = allSequences(node->left);
    vector<vector<Node*>> rightSeq = allSequences(node->right);

    // Weave together each list from the left and right sides
    for (vector<Node*> left: leftSeq) {
        for (vector<Node*> right: rightSeq) {
            vector<vector<Node*>> weaved = vector<vector<Node*>> ();
            weaveLists(left, right, weaved, prefix);
            addAll(weaved, result);
        }
    }
    return result;
}

void printList(vector<Node*> arr) {
    cout << "{";
    for (const auto& node: arr) {
        cout << node->val << ", ";
    }
    cout << "}" << endl;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    // vector<int> arr = {1,2,3};
    Node* root = minimalTree(arr, 0, arr.size() - 1);

    vector<vector <Node*>> sequences = allSequences(root);
    for (const auto& vec: sequences) {
        printList(vec);
    }
    return 0;
}