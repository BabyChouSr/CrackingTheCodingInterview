// Sort Stack


#include <iostream>
#include <stack>
using namespace std;

struct SortedStack {
    stack<int> s;
    SortedStack() : s(stack<int> ()) {}

    void printStack() {
        stack<int> printer = s;
        while (!printer.empty()) {
            cout << printer.top() << ", ";
            printer.pop();
        }
    }
    void push(int value){

        // if (s.empty()) {
        //     s.push(value); 
        //     return;
        // }
        cout << "Inserting: " << value << endl;
        stack <int> temp;
        while (!s.empty()) {
            int topElem = s.top();
            // cout << topElem << endl;
            if (value > topElem) {
                s.pop();
                temp.push(topElem);
            } else {
                break;
            }
        }
        temp.push(value);
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }

    }
    
};
int main() {
    SortedStack* s = new SortedStack();
    s->push(1);
    s->push(5);
    s->push(2000);
    s->push(4);
    s->push(2);
    s->push(3);
    s->push(999);
    s->printStack();
    return 0;
}