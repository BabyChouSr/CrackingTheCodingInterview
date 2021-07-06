// Sum Lists


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

// Approach: Sum the linked lists into an integer -> new linkedList
Node* sumLists(Node* h1, Node* h2) {
    int ans = 0;
    int multiple = 1;

    Node* curr1 = h1;
    Node* curr2 = h2;
    Node* newHead = nullptr;
    while (curr1 || curr2) {
        int add = 0;
        if (curr1) {
            add += curr1->val * multiple;
        } 
        if (curr2){
            add += curr2->val * multiple;
        }
        multiple *= 10;
        ans += add;
        curr1 =  !curr1 ? curr1 : curr1->next;
        curr2 = !curr2 ? curr2 : curr2->next;
    }

    while (ans  > 0) {
        int nextAdd = ans % 10;
        if (newHead == nullptr) {
            newHead = new Node(nextAdd);
        }
        else {insertNode(&newHead, new Node(nextAdd));}
        ans /= 10;
    }
    return newHead;
}

// Approach: Sum the linked lists and make into new linked list all in one loop
// This is given that the digits are stored in reverse order
Node* sumLists2(Node* h1, Node* h2) {
    int ans = 0;
    int carry = 0;
    Node* curr1 = h1;
    Node* curr2 = h2;
    Node* newHead = nullptr;
    while (curr1 || curr2) {
        int add = 0;
        if (curr1) {
            add += curr1->val;
        } 
        if (curr2){
            add += curr2->val;
        }
        add += carry;
        if(add > 10) {
            carry = 1;
            add %= 10;
        }
        else {
            carry = 0;
            add %= 10;
        }
        if (newHead == nullptr) {
            newHead = new Node(add);
        }
        else {
            insertNode(&newHead, new Node(add));
        }
        curr1 =  !curr1 ? curr1 : curr1->next;
        curr2 = !curr2 ? curr2 : curr2->next;
    }
    return newHead;
}

void pushFront(Node** head, int n) {
    if (head == nullptr) {
        *head = new Node(n);
    } else {
        Node* temp = new Node(n);
        temp->next = *head;
        *head = temp;
    }
}
// Approach: Sum the linked lists and make into new linked list all in one loop
// This is given that the digits are stored in forward order
Node* sumLists3(Node* h1, Node* h2) {
    int ans = 0;
    Node* carryList = nullptr;
    Node* newHead = nullptr;

    int diffSize = 0;
    int size1 = 0;
    int size2 = 0;
    Node* curr10 = h1;
    Node* curr20 = h2;
    while (curr10 || curr20) {
        if (curr10) {size1++;}
        if (curr20) {size2++;}
        curr10 = !curr10 ? curr10 : curr10->next;
        curr20 = !curr20 ? curr20 : curr20->next;
    }
    diffSize = labs(size2 - size1);
    while (diffSize > 0 ) {
        if (size1 > size2) {
            pushFront(&h2, 0);
        } else if (size1 == size2) {
            break;
        } else {
            pushFront(&h1, 0);
        }
        diffSize--;
    }

    printList(h1);
    printList(h2);
    Node* curr1 = h1;
    Node* curr2 = h2;

    while (curr1 || curr2) {
        int add = 0;
        if (curr1) {
            add += curr1->val;
        } 
        if (curr2){
            add += curr2->val;
        }
        if(add >= 10) {
            if (!carryList) {
                carryList = new Node(1);
            } else {
                insertNode(&carryList, new Node(1));
            }
            add %= 10;
        }
        else {
            if (!carryList) {
                carryList = new Node(0);
            } else {
                insertNode(&carryList, new Node(0));
            }
            add %= 10;
        }
        if (newHead == nullptr) {
            newHead = new Node(add);
        }
        else {
            insertNode(&newHead, new Node(add));
        }
        curr1 =  !curr1 ? curr1 : curr1->next;
        curr2 = !curr2 ? curr2 : curr2->next;
    }

    Node* runner = newHead;
    Node* prev = newHead;
    bool first = false;
    while (carryList != nullptr) {
        cout << "runner->val: " << runner->val << ", carryList->val: " << carryList->val << endl;
        if (!first && carryList->val == 1) {
            // Push Front the 1;
            pushFront(&newHead, 1);
        }  else {
            prev->val += carryList->val;
        }
        first = true;
        prev = runner;
        runner = runner->next;
        carryList = carryList->next;
    }
    return newHead;
}

int main() {
    Node* h1 = new Node(7);
    // insertNode(&h1, new Node(1));
    insertNode(&h1, new Node(6));

    Node* h2 = new Node(5);
    insertNode(&h2, new Node(9));
    insertNode(&h2, new Node(2));

    printList(sumLists3(h1,h2));
    return 0;
}