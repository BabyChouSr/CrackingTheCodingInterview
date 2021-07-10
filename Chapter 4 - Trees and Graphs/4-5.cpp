// Validate BST

#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    int val;
    int bf;
    Node* left;
    Node* right;
    Node () : val(0), bf(0), left(nullptr), right(nullptr) {}
    Node (int val) : val(val), bf(0), left(nullptr), right(nullptr) {}
};

// if output of this function == 0 then it's a valid BST, else it's not 
// Time Complexity: O(n)
// Space Complexity: O(h) in recursive calls which equal height of tree
// The issue is the scope of this is insufficient, this only checks the immediate left and right, however, it is possible 
// that the node->right > node but the node should actually be to the right of the root (check book for Min/Max Solution)
// ! This is not correct
int validateBST(Node* head) {
    if (head == nullptr) {return 0;}
    if (head->right != nullptr) {
        if (head->right->val < head->val) {return -1;}
    } 

    if (head->left != nullptr) {
        if (head->left->val > head->val) {return -1;}
    }
    return validateBST(head->left) + validateBST(head->right);
}

// True Conditions: All left nodes must be less than or equal to the current node, which must be less than all the right nodes
// Every time we branch left, we update the max condition, every time we branch right,  we update the min condition
// First drills all the way to the left, then slowly back up the tree, head->right

bool validateBST2(Node* head, int nmin, int nmax) {
    if (head == nullptr) {return true;}
    
    if (head->val <= nmin || head->val > nmax) {return false;}

    if (!validateBST2(head->left, nmin, head->val) || !validateBST2(head->right, head->val, nmax)) {return false;}

    return true;
}

Node* minimalTree(vector <int> arr, int low, int high) {
    if (arr.size() == 0) {return nullptr;}
    if (low > high) {return nullptr;}

    int mid = (low + high) / 2;
    Node* node = new Node(arr[mid]);
    node->left = minimalTree(arr, low, mid - 1);
    node->right = minimalTree(arr, mid + 1, high);
    return node;
} 


int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    // cout << minimalTree(arr)->val << endl;

    // Balanced Binary Search Tree Case
    Node* root = minimalTree(arr, 0, arr.size() - 1);
    cout << validateBST2(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) << endl;
    // Tree = Linked List case
    Node* root2 = new Node(1);
    root2->right = new Node(2);
    root2->right->right = new Node(3);
    root2->right->right->left = new Node(999);
    root2->right->right->right = new Node(-3);
    root2->right->right->right->right = new Node(-99);
    cout << validateBST2(root2, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) << endl;


    // Specific Case 
    Node* root3 = new Node(20);
    root3->left = new Node(10);
    root3->right = new Node(30);
    root3->left->right = new Node(25);
    cout << validateBST2(root3, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()) << endl;
    return 0;
}