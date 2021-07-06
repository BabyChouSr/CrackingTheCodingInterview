// Three in One

#include <iostream>

using namespace std;

struct MultiStack {
    int stackTot;
    int stackCapacity; // Total available capacity for each three stacks
    int* stackArray;
    int* size; // Total used capacity for each three stack

    MultiStack(int stackCapacity) : stackTot(3), stackCapacity(stackCapacity), stackArray(new int[stackTot * stackCapacity]()), size(new int[stackTot]()) {} 

    void printStack() {
        for (int i = 0; i < stackTot; i++) {
            cout << "stackNum: " << i << endl;
            for (int j = 0; j < size[i]; j++) {
                cout << stackArray[i * stackCapacity + j] << ", ";
            }
            cout << endl;
        }
    }

    void push(int stackNum, int value) {
        if (!isFull(stackNum)) {
            stackArray[stackNum * stackCapacity + size[stackNum]] = value;
            size[stackNum]++;
        }
    }
    void pop(int stackNum) {
        if (stackArray[stackNum * stackCapacity + size[stackNum] - 1]) {
            stackArray[stackNum * stackCapacity + size[stackNum] - 1] = 0;
            size[stackNum]--;
        }
    }
    int top(int stackNum) {
        if (isEmpty(stackNum)) {
            return 0;
        }
        return stackArray[stackNum * stackCapacity + size[stackNum] - 1];
    }
    bool isEmpty(int stackNum) {
        return size[stackNum] == 0;
    }
    bool isFull(int stackNum) {
        return size[stackNum] == stackCapacity;
    }

};

int main() {
    MultiStack* mstack = new MultiStack(5);
    mstack->push(0, 1);
    mstack->push(0, 2);
    mstack->push(0, 3);
    mstack->push(1, 1);
    mstack->push(1, 2);
    mstack->push(1, 3);
    mstack->push(1, 999);
    mstack->push(2, 2);
    mstack->push(2, 3);
    mstack->push(2, 7);
    mstack->printStack();

    return 0;
}