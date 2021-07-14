// Random Node: You are implementing a binary search tree class from scratch, which, in addition
// to insert, find, and delete, has a method getRandomNode() which returns a random node
// from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
// for getRandomNode, and explain how you would implement the rest of the methods.

#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>

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
    int size;
    BST() : root(), size(0) {}
    BST(Node* root) : root(root), size(1) {}

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
        if (node == nullptr) {
            size++;
            return new Node(value);
        }

        if (value > node->val) {
            node->right = insert(node->right, value);
        }
        else if (value <= node->val) {
            node->left = insert(node->left, value);
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
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value > node->val) {
            node->right = deleteNode(node->right, value);
        } else if (value < node->val) {
            node->left = deleteNode(node->left, value);
        } else { // This is the node that has to be deleted
            size--;
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) { // No child case
                    temp = node;
                    node = nullptr;
                }
                else { // One child
                    *node = *temp; // Copy the contents of that one child
                }
                free(temp);
            }
            else { // If there are two children
                Node* temp = miniValueNode(node->right); // Gives the inorder successor
                node->val = temp->val;
                node->right = deleteNode(node->right, temp->val);
            }
        }
        if (node == nullptr) {
            return node;
        }
        node->height = calcHeight(node);
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

    int calcSize(Node* n) {
        if (n == nullptr) {return 0;}
        return 1 + calcSize(n->left) + calcSize(n->right);
    }

    // Time Complexity: O(N) since it may traverse entire tree
    // Space Complexity: O(N)
    Node* getRandomNode() {
        srand (time(NULL));
        int random_number = rand() % size;
        cout << random_number << endl;
        int count = 0;
        queue <Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* x = q.front();
            q.pop();
            if (count == random_number) {
                return x;
            } 
            if (x->left != nullptr) {q.push(x->left);}
            if (x->right != nullptr) {q.push(x->right);}
            count++;
        }
        return nullptr;
    }

    // Time Complexity: O(log(N))
    Node* getRandomNode2(Node* node){
        // NORMALLY WE WOULD HAVE THE SIZE STORED IN THE NODE CLASS ITSELF BUT 
        // TO SIMULATE MORE EASILY, I WROTE A SIZE() function
        srand (time(NULL));
        int randomNumber = rand() % calcSize(node);
        int leftSize = left == nullptr ? 0 : calcSize(node->left);
        if (randomNumber < leftSize) {
            return getRandomNode2(node->left);
        }   else if (randomNumber == leftSize) {
            return node;
        } else {
            return getRandomNode2(node->right);
        }
    }

    Node* getIthNode(Node* node, int index) {
        int leftSize = root->left == nullptr ? 0 : calcSize(root->left);
        if (index < leftSize) {
            return getIthNode(node->left, index);
        } else if (index == leftSize) {
            return node;
        } else {
            return getIthNode(node->right, index - (leftSize + 1));
        }

    }


    // Time Complexity: O(log(N))
    // BENEFITS: Don't need to continuously call the random generator
    Node* getRandomNode3(Node* node) {
        srand(time(NULL));
        int randomNumber = rand() % calcSize(node);
        return getIthNode(node, randomNumber);
    }

};

void preOrder(Node* n) {
    if (n == nullptr) {return;}
    cout << n->val << endl;
    if (n->left != nullptr) {preOrder(n->left);}
    if (n->right != nullptr) {preOrder(n->right);}
}

int main() {
    BST* bst = new BST(new Node(5));
    bst->root = bst->insert(bst->root, 10);
    bst->root = bst->insert(bst->root, 15);
    bst->root = bst->insert(bst->root, 20);
    bst->root = bst->insert(bst->root, 25);
    bst->root = bst->insert(bst->root, 30);

    preOrder(bst->root);
    cout << bst->size << endl;

    cout << "POST DELETION OF 15:" << endl;
    bst->root = bst->deleteNode(bst->root, 15);
    preOrder(bst->root);
    cout << bst->size << endl;

    // cout << "GET RANDOM NODE 1" << endl;
    // cout << bst->getRandomNode()->val << endl;

    // cout << "GET RANDOM NODE 2" << endl;
    // cout << bst->getRandomNode2(bst->root)->val << endl;

    cout << "GET RANDOM NODE 3" << endl;
    cout << bst->getRandomNode2(bst->root)->val << endl;
    return 0;
}