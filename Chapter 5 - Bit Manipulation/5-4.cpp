// Next Number

#include <iostream>

using namespace std;


// Strategy is to find the first non trailing zero and turn it into one
// Then, every number after that index p, maintain same number of ones by appending to the end of the number
int getNext(int n) {
    int c0 = 0; // number of 0s
    int c1 = 0; // number of 1s
    int c = n;
    while ((( c & 1) == 0 ) && (c != 0)) { // 1st Condition ensures bit = 0, 2nd condition ensures not empty
        c0++;
        c >>= 1;
    }
    while (((c & 1) == 1)) { // same thing as before except with 1
        c1++;
        c >>= 1;
    }

    int p = c1 + c0; // the index of trailing 0

    n |= (1 << p); // Add 1 to the trailing zero index
    n &= ~((1 << p) - 1); // Clear all bits to the right of p
    n |= (1 << (c1 - 1)) - 1; // Add (c1 -1) ones on the right
    return n;
}

int getPrev(int n) {
    int c0 = 0;
    int c1 = 0;
    int c = n;

    // Find trailing ones first
    while (((c & 1) == 1)) { // same thing as before except with 1
        c1++;
        c >>= 1;
    }
    
    // Find zeroes afterwards
    while ((( c & 1) == 0 ) && (c != 0)) { // 1st Condition ensures bit = 0, 2nd condition ensures not empty
        c0++;
        c >>= 1;
    }

    int p = c0 + c1; // this is the rightmost non-trailing one index

    n &= ~0 << (p+1); // clear all bits from 0 to p
    n |= ((1 << (c1 + 1)) - 1) <<(c0-1);  // add c1 + 1 ones followed by c0 - 1 zeroes
    return n;
}

int main () {
    cout << getNext(1775) << endl;
    cout << getPrev(1775) << endl;
    return 0;
}