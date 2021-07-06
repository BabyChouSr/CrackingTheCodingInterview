// Stack Min

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    int minimum;
    Node() : val(0), next(nullptr), minimum(0) {}
    Node(int val) : val(val), next(nullptr), minimum(val) {}
};

struct Stack {
    Node* head;
    int stackSize;
    Stack() : head(nullptr), stackSize(0) {}
    Stack(Node* head) : head(head), stackSize(1) {}

    void printStack() {
        if (!stackSize) {return;}
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->val << ", ";
            curr = curr->next;
        }
        cout << endl;
    }
    void push(int value) {
        if (head == nullptr) {
            head = new Node(value);
            stackSize++;
            return;
        }
        Node* curr = new Node(value);
        int headMin = head->minimum;
        curr->next = head;
        head = curr;
        head->minimum = (head-> minimum > headMin) ? headMin : head->minimum;
        stackSize++;
        return;
    }
    Node* top () {
        if (!head) {return nullptr;}
        return head;
    }
    void pop() {
        if (!head) {return;}
        Node* discard = head;
        head = head->next;
        delete discard;
        stackSize--;
    }
    bool isEmpty() {
        return stackSize == 0;
    }

    int getMinimum() {
        return head->minimum;
    }
};



int main() {
    Stack* s = new Stack();
    s->push(5);
    s->push(10);
    s->printStack();
    s->push(2);
    s->push(1);
    s->pop();
    s->push(-1);
    s->pop();
    s->push(1400);
    s->push(100);
    cout << s->getMinimum() << endl;
    return 0;
}