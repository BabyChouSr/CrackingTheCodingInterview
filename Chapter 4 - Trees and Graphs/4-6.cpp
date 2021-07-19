// In Order-Successor
// In Binary Tree, Inorder successor of a node is the next node in Inorder traversal of the Binary Tree. 
// Inorder Successor is NULL for the last node in Inorder traversal. 
// In Binary Search Tree, Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of the input node. 
// So, it is sometimes important to find next node in sorted order.

#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

// struct Node {
//     int val;
//     int bf;
//     Node* left;
//     Node* right;
//     Node () : val(0), bf(0), left(nullptr), right(nullptr) {}
//     Node (int val) : val(val), bf(0), left(nullptr), right(nullptr) {}
// };

struct Node {
    int val;
    int bf;
    Node* left;
    Node* right;
    Node* parent;
    Node () : val(0), bf(0), left(nullptr), right(nullptr), parent(nullptr) {}
    Node (int val) : val(val), bf(0), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Time Complexity: O(n) 
// Space Complexity: O(n)
// Solved for different type of question where we look for the next node on the same level
// ! This is not correct
Node* successor(Node* head, Node* n) {
    if (n == nullptr) {return nullptr;}
    vector <Node*> current;
    current.push_back(head);

    bool found = false;
    while (!current.empty()) {
        vector <Node*> parents = current;
        current = vector<Node*> ();
        for (const auto& node: parents) {
            Node* candRight = node->right;
            Node* candLeft = node->left;
            if (found) {
                if (candLeft != nullptr) {return candLeft;}
                else if (candRight != nullptr) {return candRight;}
            }
            if (node->left->val == n->val) {
                found = true;
                if (candRight != nullptr) {return candRight;}
            } else if (node->right->val == n->val) {
                found = true;
            }
            if (candLeft != nullptr) {current.push_back(candLeft);}
            if (candRight != nullptr) {current.push_back(candRight);}


        }
    }
    return nullptr;
}

// ! This is correct
// 1. If the node n has a right subtree: return the left most node of the right subtree
// 2. If node n has no right subtree, go up the subtree until n is the left child of its parent
Node* successor2(Node* head, Node* n) {
    if (n->right != nullptr) {
        Node* drill = n->right;
        while (drill->left != nullptr) {
            drill = drill->left;
        }
        return drill;
    } else {
        Node* p = n->parent;
        while (n != nullptr && n == p->right) {
            p = p->parent;
            n = n->parent;
        }
    }
    return n->parent;
}

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    } else {
        Node* temp;
        if (data <= node->val) {
            temp = insert(node->left, data);
            node->left = temp;
            temp->parent = node;
        } else {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }
    }
    return node;
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
    // Node* root = nullptr;

    // for (const auto& num: arr) {
    //     root = insert(root, num);
    // }

    // TEMP = 6
    Node* temp = root->left->right;
    cout << temp->val << endl;
    cout << successor2(root, temp)->val << endl;

    // TEMP = 7
    Node* temp2 = root->left->right->right;
    cout << temp2->val << endl;
    cout << successor2(root, temp2)->val << endl;

    //TEMP = 13
    Node* temp3 = root->right->right->left;
    cout << temp3->val << endl;
    cout << successor2(root, temp3)->val << endl;

    //TEMP = 8
    Node* temp4 = root;
    cout << temp4->val << endl;
    cout << successor2(root, temp4)->val << endl;
    return 0;
}