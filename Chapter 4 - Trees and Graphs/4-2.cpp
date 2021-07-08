// Minimal Tree


#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node () : val(0), left(nullptr), right(nullptr) {}
    Node (int val) : val(val), left(nullptr), right(nullptr) {}
    Node(int val, Node* left, Node* right) : val(val), left(left), right(right) {}
    void insertNode(Node* n) {
        if (n->val < val) {right = n;}
        else {left = n;}
    }

};
void printList(Node* n) {   
    if (n == nullptr) {return;}
    else {
        cout << n->val << endl;
        printList(n->left);
        printList(n->right);
    }
}

// Recursive algorithm that essentially continuously divides the array to find the left and right nodes of some mid node
// node = mid of array
// node->left = mid of lower sub-array
// node->right = mid of higher sub-array
Node* minimalTree(vector <int> arr, int low, int high) {
    if (arr.size() == 0) {return nullptr;}
    if (low > high) {return nullptr;}

    int mid = (low + high) / 2;
    Node* node = new Node(arr[mid]);
    node->left = minimalTree(arr, low, mid - 1);
    node->right = minimalTree(arr, mid + 1, high);
    return node;
}   

int main () {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    // cout << minimalTree(arr)->val << endl;
    printList(minimalTree(arr, 0, arr.size() - 1));
    return 0;
}