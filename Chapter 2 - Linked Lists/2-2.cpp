// Return Kth to Last

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

struct prevCurr {
    Node* curr;
    Node* prev;
    prevCurr() : curr(nullptr), prev(nullptr) {}
};

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->val << "-->";
        n = n->next;
    }
    cout << endl;
}

void insertNode(Node* head,Node *n) {
    Node* temp = head;
    if(head == nullptr) {
        temp = n;
        temp->next = nullptr;
        return;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n;
    return;
} 

// Approach is to first find the size of the array then just find (size - k)'th element
Node* kthToLast(Node* head, int k) {
    if (head == nullptr) {return nullptr;}
    int size = 0;
    Node* temp = head;
    while (temp != nullptr) {
        temp = temp->next;
        size++;
    }
    Node* runner = head;
    int count = 0;
    while (runner != nullptr &&  count < (size - k)) {
        runner = runner->next;
        count++;
    }
    return runner;
}

//Approach is to recursively find the k'th element by backtracking
// Ineffiency: Uses space to have to delete the element
Node* kthToLast2(Node* head, int k) {
    Node* temp = head;
    Node* prev = head;

    // Time Complexity: O(n * k)
    while (prev->next->next != nullptr) {
        prev = prev->next;
    }
    if (k == 1) {
        return prev->next;
    }
    else {

        delete prev->next;
        prev->next = nullptr;
        return kthToLast2(head, k - 1);
    }

}


//Approach is to iteratively find the k'th element by backtracking
//Ineffiency: Uses space to have to delete the element
Node* kthToLast3(Node* head, int k) {
    Node* temp = head;
    Node* prev;
    
    // Time Complexity: O(n * k)
    while(k > 1) {
        prev = head;
        while (prev->next->next != nullptr) {
            prev = prev->next;
        }
        if (k== 1) {
            return prev->next;
        }
        else {
            delete prev->next;
            prev->next = nullptr;
            k-=1;
        }

    }
    return prev;
}

//Approach: Recursive drilling by utilizing an index
// and wait until index = k
// works because the index only starts adding at the end of recursive call stack (adds at the end)

Node* kthToLastRecursive(Node* head, int k, int& i) { // notice it's a reference to i because we want to be able to change it and reflect globally
    if (head == nullptr) {return nullptr;}
    Node* node = kthToLastRecursive(head->next, k, i);
    i++;
    if (i ==k) {return head;}
    return node;
}

Node* kthToLast4(Node* head, int k) {
    int i = 0;
    return kthToLastRecursive(head, k, i);
}

//Approach: Iterative, have one ptr1 and ptr2
// 1. ptr1 travels k steps forward
// 2. ptr2 starts and travels with ptr1 until ptr1 == nullptr
// 3. return ptr2 when ptr1 == nullptr

Node* kthToLast5(Node *head, int k) {
    Node* ptr1 = head;
    Node* ptr2 = head;
    int i = 0; 
    while (ptr1->next && i <k) {
        ptr1 = ptr1->next;
        i++;
    }
    while(ptr1 != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2;
}
int main() {
    int k = 5;
    Node* head = new Node(10);
    insertNode(head, new Node(11));
    insertNode(head, new Node(12));
    insertNode(head, new Node(13));
    insertNode(head, new Node(14));
    insertNode(head, new Node(15));
    printList(head);
    cout << kthToLast5(head, k)->val << endl;
    return 0;
}