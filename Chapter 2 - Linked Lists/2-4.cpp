// Partition

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->val << "-->";
        n = n->next;
    }
    cout << endl;
}

void insertNode(Node** head, Node* n) {
    // inserts Node to the end of the list
    Node* curr = *head;
    if (head == nullptr) {
        *head = n;
        n->next = nullptr;
        return;
    }
    while (curr->next != nullptr) {
        curr = curr->next; // get Tail
    }
    curr->next = n;
    return;
}

void pushFront(Node** head, int value) {
    Node* temp = new Node(value);
    temp->next = *head;
    *head = temp;
    // temp = nullptr;
    // delete temp;
}
Node* partition(Node* head, int p) {
    //Approach: Loop through and if curr->val < p then insert at beginning
    Node* left = new Node();
    bool leftHead = false;
    Node* right = new Node();
    bool rightHead = false;

    Node *leftEnd = new Node();
    Node *rightEnd = new Node();
    Node* curr = head;

    // Time Complexity = O(N)
    // Space Complexity = O(N) because we creating a whole new list and then concantenating
    // Another method worth mentioning is creating a new list then appending values > p to the tail and values < p to the head
    while (curr != nullptr) {
        if (curr->val < p && !leftHead) {
            left->val = curr->val;
            leftEnd = left;
            leftHead = true;
        } else if (curr->val < p) {
            leftEnd->next = new Node(curr->val);
            leftEnd = leftEnd->next;
        } else if (curr->val > p && !rightHead) {
            right->val = curr->val;
            rightEnd = right;
            rightHead = true;
        } else {
            rightEnd->next = new Node(curr->val);
            rightEnd = rightEnd->next;
        }
        curr = curr->next;
    }
    leftEnd->next = right;
    return left;

}

int main(){
    Node* head = new Node(3);
    insertNode(&head, new Node(5));
    insertNode(&head, new Node(8));
    insertNode(&head, new Node(5));
    insertNode(&head, new Node(10));
    insertNode(&head, new Node(2));
    insertNode(&head, new Node(1));
    pushFront(&head,  16);
    pushFront(&head,  4);
    pushFront(&head,  3);
    pushFront(&head,  1);
    printList(head);
    Node* newPartitionList = partition(head, 5);
    printList(newPartitionList);
    return 0;
}