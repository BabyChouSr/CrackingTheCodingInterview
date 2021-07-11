// First Common Ancestor
// TODO: Include the implementation for without links

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(int val) : val(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Time Complexity: O (depth^2)
Node* fca(Node* x, Node* y) {
    Node* xp;
    Node* yp;
    Node* y_s;
    Node* x_0 = x;
    Node* y_0 = y;
    if (x != nullptr) {xp = x->parent;}
    if (y != nullptr) {yp = y->parent;}
    y_s = y_0;
    while (xp != nullptr) {
        y_0 = y_s;
        yp = y_s->parent;
        while (yp != nullptr) {
            if (xp->val == yp->val) {
                return xp;
            }
            y_0 = yp;
            yp = yp->parent;
        }
        x_0 = xp;
        xp = xp->parent;
    }
    return xp;
}
int depth(Node* n) {
    Node* curr = n;
    int d = 0;
    while (curr != nullptr) {
        curr = curr->parent;
        d++;
    }
    return d;
}

// TAKING SIMILAR APPROACH To finding intersection of a linked list
// Time Complexity: O(d) where d is the depth of the tree
Node* fca2(Node*x, Node* y) {
    int delta = depth(x) - depth(y); // if negative then depth(x) < depth(y)
    Node* p = delta > 0 ? y : x; // longer one 
    Node* q = delta > 0 ? x : y; // shorter one
    for (int i = 0; i < delta; i++) {
        p = p->parent;
    }
    while (p && q) {
        if (p == q) {return p;}
        p = p->parent;
        q = q->parent;
    }
    return nullptr;
}

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

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    // Balanced Binary Search Tree Case
    Node* root = minimalTree(arr, 0, arr.size() - 1);

    // 13 and 15, expected: 14
    cout << fca2(root->right->right->left, root->right->right->right)->val << endl;

    // 1 and 5, expected: 4
    cout << fca2(root->left->left->left, root->left->right->left)->val << endl;

    // 1 and 13, expected: 8
    cout << fca2(root->left->left->left, root->right->right->left)->val << endl;

    // Node* root = nullptr;
    return 0;
}