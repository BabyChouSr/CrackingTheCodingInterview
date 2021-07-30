// Conversion

#include <iostream>

using namespace std;

// Iterate over both x and y and check each bit to see if they are equivalent to each other
int conversion(int x, int y) {
    int num = 0;
    while (x > 0) {    
        if ((x & 1) != (y & 1) ) {
            num++;
        }
        x >>= 1;
        y >>= 1;
    }
    return num;
}

//XOR x and y and check when they is a 1 which means there is a difference between the two
int conversion2(int x, int y) {
    int count = 0;
    int c =  x ^ y;
    while (c != 0) {
        count += c & 1; // checks if it's equivalent to 1
        c >>= 1;
    }
    return count;
}

int main() {
    int x = 29;
    int y = 15;
    cout << conversion2(x,y) << endl;
    return 0;
}