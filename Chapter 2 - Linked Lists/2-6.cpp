// Palindrome
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

void insertNode(Node *& head, int n) {
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

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->val << "-->";
        n = n->next;
    }
    cout << endl;
}

bool isPalindrome(Node* head){
    int isOdd = 0;
    Node* curr = head;
    vector<int> counts(10);

    while (curr != nullptr) {
        int loc = curr->val;
        if (counts[loc] % 2 == 0) {
            isOdd++;
        } else {
            isOdd--;
        }
        counts[loc]++;
        curr = curr->next;
    }
    return isOdd <= 1;
}

int toggle(int bitVector, int loc) {
    int mask = 1 << loc;
    bitVector ^= mask;
    return bitVector;
}

bool isPalindrome2(Node* head){
    Node* curr = head;
    int bitVector = 0;

    while (curr != nullptr) {
        int loc = curr->val;
        bitVector = toggle(bitVector, loc);
        curr = curr->next;
    }
    return bitVector == 0 || ((bitVector & (bitVector - 1 )) == 0);
}

int main(){
    Node* head = new Node(1);
    insertNode(head, 0);
    insertNode(head, 0);
    insertNode(head, 1);
    insertNode(head, 2);
    // insertNode(head, 5);
    printList(head);
    cout << isPalindrome2(head) << endl;
    return 0;
}