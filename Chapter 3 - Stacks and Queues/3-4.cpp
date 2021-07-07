// Queue via Stacks
// Basic idea is to have one normal stack and the other stack being the reversed version which serves to equal a Queue

#include <iostream>
#include <stack>

using namespace std;

struct MyQueue {
    stack<int> main_stack;
    stack<int> temp_stack;

    MyQueue() {}

    void printQueue() {
        cout << "TEMP STACK: " << endl;
        while (!temp_stack.empty()) {
            cout << temp_stack.top() << endl;
            temp_stack.pop();
        }

        cout << "MAIN STACK: " << endl;
        while (!main_stack.empty()) {
            cout << main_stack.top() << endl;
            main_stack.pop();
        }
    }
    
    void printStack(stack<int> s) {
        while(!s.empty()) {
            cout << s.top() << endl;
            s.pop();
        }
    }
    void push(int value) {
        int topElem;
        temp_stack = stack<int> ();
        cout << "Inserting: " << value << endl;
        main_stack.push(value);
        stack<int> main_stack2 = main_stack;
        while (!main_stack2.empty()) {
            cout << main_stack2.top() << endl;
            temp_stack.push(main_stack2.top());
            main_stack2.pop();
        }
    }
    void pop() {
        temp_stack.pop();
        return;
    }
    
    int top() {
        return temp_stack.top();
    }

    bool isEmpty() {
        return main_stack.empty();
    }
};

int main() {
    MyQueue* queueT = new MyQueue();
    queueT->push(1);
    queueT->push(2);
    queueT->push(3);
    queueT->push(4);
    queueT->push(5);
    queueT->printQueue();
    queueT->pop();
    queueT->printQueue();
    return 0;
}