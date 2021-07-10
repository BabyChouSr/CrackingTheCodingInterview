// Check Balanced

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int val;
    int bf;
    Node* left;
    Node* right;
    Node () : val(0), bf(0), left(nullptr), right(nullptr) {}
    Node (int val) : val(val), bf(0), left(nullptr), right(nullptr) {}
};

int height(Node* node) {
    if (node == nullptr) {return 0;}
    return 1 + max(height(node->left), height(node->right));
}

int balance(Node *node) {
    if (node == nullptr) {return 0;}
    return height(node->right) - height(node->left);
}

//  Time Complexity: O(N  * log N) since it traverses entire tree
//  Space Complexity: O(n) since it has a queue that contains the whole tree
bool checkBalanced (Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* x = q.front();
        q.pop();
        if (labs(balance(x)) > 1) {return false;}
        if (x->left != nullptr) {q.push(x->left);}
        if (x->right != nullptr) {q.push(x->right);}
    }
    return true;
}

// We notice that the algorithm above must traverse the entire tree and calculate each height then balance factor
// but in reality, you could check the balance factor while calculating the height
// We could have an error number to be the case that a node is unbalanced (in this case, -1)
// Time Complexity: O(n)
// Space Complexity: O(H) where H is the height of the tree
int checkBalanced2(Node* root) {
    if (root == nullptr) {return 0;}

    int leftHeight = checkBalanced2(root->left);

    if (leftHeight == -1) {return -1;}

    int rightHeight = checkBalanced2(root->right);

    if (rightHeight == -1) {return -1;}

    int balance = labs(leftHeight - rightHeight);
    if (balance > 1) {return -1;}
    return 1 + max(checkBalanced2(root->left), checkBalanced2(root->right));
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
    cout << (checkBalanced2(root) != -1) << endl;

    // Tree = Linked List case
    Node* root2 = new Node(1);
    root2->right = new Node(2);
    root2->right->right = new Node(2);
    root2->right->right->right = new Node(2);
    cout << (checkBalanced2(root2) != -1) << endl;
    return 0;
}