// Intersection

#include <iostream>

using namespace std;
struct Node{
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

void insertNode(Node* &head, int n) {
    if (head == nullptr) {
        head = new Node(n);
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new Node(n);
    }
    return;
}

// Time Complexity: O(A * B) which is inefficient
Node* intersect(Node* h1, Node* h2) {
    Node* ptr1 = h1;
    Node* ptr2 = h2;
    while (ptr1 != nullptr) {
        ptr2 = h2;
        while (ptr2 != nullptr) {
            if (ptr1 == ptr2) {
                return ptr1;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return nullptr;
}

int lenList(Node* n) {
    int size = 0;
    while (n != nullptr) {
        size++; 
        n = n->next;
    }
    return size;
}
// Time Complexity: O(B) which is better where B > A
// Takes advantage of the fact that if it's intersecting at one part of the lsit then rest of the list will be the same
Node* intersect2(Node* h1, Node* h2) {
    int len1 = lenList(h1);
    int len2 = lenList(h2);
    Node* ptr1 = len1 >= len2 ? h1 : h2; // ptr1 is pointing to longer or equal list in length
    Node* ptr2 = len1 >= len2 ? h2 : h1;

    for (int i = 0; i < labs(len2 - len1); i++) {
        ptr1 = ptr1->next;
    }
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2) {return ptr1;}
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return nullptr;
}

int main() {
    Node* head = new Node(1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
    insertNode(head, 7);

    printList(head);
    cout << intersect2(head, head->next->next)->val << endl;
    return 0;
}