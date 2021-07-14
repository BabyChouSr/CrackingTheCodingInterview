// Random Node: You are implementing a binary search tree class from scratch, which, in addition
// to insert, find, and delete, has a method getRandomNode() which returns a random node
// from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
// for getRandomNode, and explain how you would implement the rest of the methods.

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    int height;
    Node* left;
    Node* right;
    Node* parent;
    Node () : val(0), height(0), left(nullptr), right(nullptr) {}
    Node (int val) : val(val), height(0), left(nullptr), right(nullptr) {}
};

struct BST {
    Node* root;
    BST() : root() {}
    BST(Node* root) : root(root) {}

    int calcHeight(Node* n) {
        if (n == nullptr) {return 0;}
        return 1 + max(calcHeight(n->left), calcHeight(n->right));
    }

    int balanceFactor(Node* n) {
        if (n==nullptr) {return 0;}
        return calcHeight(n->left) - calcHeight(n->right);
    }

    Node* rightRotate(Node* n) {
        Node* x = n->left;
        Node* T1 = x->right;

        x->right = n;
        n->left = T1;

        n->height = calcHeight(n);
        x->height = calcHeight(x);

        return x;
    }
    Node* leftRotate(Node* n) {
        Node* y = n->right;
        Node* T2 = y->left;

        y->left = n;
        n->right = T2;

        n->height = calcHeight(n);
        y->height = calcHeight(y);

        return y;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {return new Node(value);}

        if (value > node->val) {
            return insert(node->right, value);
        }
        else if (value <= node->val) {
            return insert(node->left, value);
        }

        node->height = calcHeight(node);
        //TODO: Add Balance Factor Update and Rotation
        int balance = balanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->val) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->val) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Right Left Case
        if (balance < -1 && value < node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    
    Node* find(int value) {
        queue <Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* x = q.front();
            q.pop();
            if (x->val == value) {return x;}
            if (x->left != nullptr) {
                q.push(x->left);
            }
            if (x->right != nullptr) {
                q.push(x->right);
            }
        }
        return nullptr;
    }

    Node* miniValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) {return root;}
        if (value > root->val) {
            return deleteNode(root->right, value);
        } else if (value < root->val) {
            return deleteNode(root->left, value);
        } else { // This is the node that has to be deleted
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) { // No child case
                    temp = root;
                    root = nullptr;
                }
                else { // One child
                    *root = *temp; // Copy the contents of that one child
                }
                delete temp;
            }
            else { // If there are two children
                Node* temp = miniValueNode(root->right); // Gives some random node
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }

        if (root == nullptr) {
            return root;
        }
        root->height = calcHeight(root);
        int balance = balanceFactor(root);

        // Left Left Case
        if (balance > 1 && value < root->left->val) {
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && value > root->right->val) {
            return leftRotate(root);
        }

        // Left Right Case
        if (balance > 1 && value > root->left->val) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        
        // Right Left Case
        if (balance < -1 && value < root->right->val) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
        

    }

};

int main() {

    return 0;
}