// Delete Middle Node
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

void deleteMiddleNode(Node *mid) {
    if (!mid || !mid->next) {return;}
    // Commented code doesn't work because the temp->next->next only contains the next's next not rest
    // Node* temp = mid;
    // temp->val = temp->next->val;
    // temp->next = temp->next->next;
    // temp->next = nullptr;
    // delete temp->next;
    Node *nextNode = mid->next;
    mid->val = nextNode->val;
    mid->next = nextNode->next;
    delete nextNode;
}

int main(){
    Node* head = new Node(10);
    Node* x = new Node(1010);
    insertNode(head, new Node(11));
    insertNode(head, new Node(12));
    insertNode(head, x);
    insertNode(head, new Node(13));
    insertNode(head, new Node(14));
    insertNode(head, new Node(15));
    printList(head);
    deleteMiddleNode(x);
    printList(head);
    return 0;
}