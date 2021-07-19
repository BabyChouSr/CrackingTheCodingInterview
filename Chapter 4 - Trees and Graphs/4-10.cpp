// Check Subtree

#include <iostream>
#include <vector>
#include <string>

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

void preorderTraversal(Node* n, string & prevString) {
    if (n == nullptr) {
        prevString += to_string(-1);
        return;
    }
    prevString += to_string(n->val);
    
    preorderTraversal(n->left, prevString);
    preorderTraversal(n->right, prevString);
}

// Approach:
// 1. Fill in all null nodes with a place holder value: -1
// 2. Do a preorder traversal of t2 and t1 and create string with each node visited
// 3. Compared to see if string of t2 is a substring of t1
// Time Complexity: O (n*m) where n and m are the number of nodes in T1 and T2 respectively
// Space Complexity: O(n+m) 
bool checkSubtree(Node* t1, Node* t2) {
    string s_t1 = "";
    string s_t2 = "";
    preorderTraversal(t1, s_t1);
    preorderTraversal(t2, s_t2);
    cout << s_t1 << endl;
    cout << s_t2 << endl;
    
    // Check if substring
    int diffLength = s_t1.length() - s_t2.length();
    for (int i = 0; i < s_t2.length(); i++) {
        if (s_t1[diffLength++] != s_t2[i]) {
            return false;
        }
    }
    return true;
}

// SECOND IMPLEMENTATION OF algorithm
// Time Complexity: O(n * m) given some assumptions, could be tighter (check book)
// Space Complexity: O(log(n) + log(m)) in recursive calls if balanced, if unbalanced then O(n + m)

// Matches the tree by drilling through the left and right subtrees of r1 and r2
bool matchTree(Node* r1, Node* r2) {
    if (r1 == nullptr && r2 == nullptr) {
        return true;
    } else if (r1 == nullptr || r2 == nullptr ) { // exactly one tree is empty, so they don't match
        return false;
    } else if (r1->val != r2->val) {
        return false;
    } else {
        return matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right);
   }
}

// This function essentially constructs the subtree by recursively going to the left or right then checking 
// if the root node of r1 is equal to root of r2 (notice that r2 is not changing at all throughout recursive calls)
bool subTree(Node* r1, Node* r2) {
    if (r1 == nullptr) { // base case, the node is nullptr so can't serve as our root
        return false;
    } else if (r1->val == r2->val && matchTree(r1, r2)) { //if roots match, then we can try to match trees
        return true;
    } 
    return subTree(r1->left, r2) || subTree(r1->right, r2); //return true if either the left or right node that serves as root matches
}

bool containsTree(Node* t1, Node* t2) {
    if (t2 == nullptr) {return true;}
    return subTree(t1, t2);
}



int main() {
    // vector<int> arr = {5,1,2,4,2};
    // vector<int> arr = {1,2,3};
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << containsTree(root->left->left, root->left->left) << endl;
    return 0;
}