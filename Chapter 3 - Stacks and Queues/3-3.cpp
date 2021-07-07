// Stack of Plates

#include <iostream>
#include <vector>

using namespace std;
struct SetOfStacks {
    int threshold;
    vector<vector<int>> stacks;
    
    SetOfStacks(int threshold) : threshold(threshold) {}

    void printStacks() {
        int i = 0;
        for (const auto& stack: stacks) {
            cout << "Stack Num: " << i << endl;
            for (const auto& val: stack) {
                cout << val << ", ";
            }
            cout << endl;
            i++;
        }
    }
    void push(int value) {
        for (int i = 0; i < stacks.size(); i++) {
            if (isFull(i) && i != stacks.size() - 1) {
                continue;
            } else if (!isFull(i)) {
                stacks[i].push_back(value);
                return;
            }
        }
        vector<int> stack;
        stack.push_back(value);
        stacks.push_back(stack);
    }

    void pop() {
        stacks[stacks.size() - 1].pop_back();
    }

    bool isFull(int stackNum) {
        return stacks[stackNum].size() >= threshold;
    }
};
int main() {
    SetOfStacks* s = new SetOfStacks(5);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->printStacks();
    return 0;
}