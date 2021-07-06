// Loop Detection
#include <iostream>
#include <vector>

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

// Issue is this requires two while loops first for finding loop then finding start 
// Can we put these two together?
// Also this works using value not reference of the linked list node
Node* loopDetection(Node* head) {
    Node* curr = head;
    vector<bool> vec(10);

    int value = -1;
    while (curr != nullptr) {
        int loc = curr->val;
        if (vec[loc] == false) {vec[loc] = true;}
        else if (vec[loc] == true) {value = curr->val;}
        curr = curr->next;
    }
    curr = head;
    while (curr != nullptr) {
        if (curr->val == value) {return curr;}
        curr = curr->next;
    }
    return nullptr;
}

bool loopDetection2(Node* head) {
    Node* slowptr = head;
    Node* fastptr = head;
    Node* slowptrPrev = head;

    while (slowptr && fastptr && fastptr->next) {
        slowptrPrev = slowptr;
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        // cout << "slowptrPrev: " << slowptrPrev->val << endl;
        if (slowptr == fastptr) {
            Node* ptr1 = slowptr;
            Node* ptr2 = head;
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            cout << "Loop Node: " << ptr2->val << endl;
            ptr2->next = nullptr;
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    head->next->next->next->next = head->next;
    cout << loopDetection2(head) <<endl;
    printList(head);
    return 0;
}