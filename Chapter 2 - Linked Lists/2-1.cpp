// Remove Dups

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->val << "-->";
        n = n->next;
    }
    cout << endl;
}

void insertNode(Node* head, Node* n) {
    // inserts Node to the end of the list
    Node* curr = head;
    if (head == nullptr) {
        head = n;
        n->next = nullptr;
        return;
    }
    while (curr->next != nullptr) {
        curr = curr->next; // get Tail
    }
    curr->next = n;
    return;
}

// Space Complexity: O(n)
// Time Complexity: O(n)
void removeDups(Node *n) {
    vector <int> values;
    Node* curr = n;
    Node* prev = NULL;
    while (curr != nullptr) {
        if (find(values.begin(), values.end(), curr->val) != values.end()) {
            prev->next = curr->next;
            curr = curr->next;
        }
        else {
            values.push_back(curr->val);   
            prev = curr;
            curr = curr->next;
        }
    }
    delete curr;
}

int main() {
    Node* head = new Node(10);
    insertNode(head, new Node(10));
    insertNode(head, new Node(10));
    insertNode(head, new Node(10));

    printList(head);
    removeDups(head);
    printList(head);
    return 0;
}