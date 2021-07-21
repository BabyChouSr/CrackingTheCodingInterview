// Insertion

#include <iostream>

using namespace std;



int insertion(int n, int m, int i, int j) {

    // First need to create a mask to clear bits i through j in n
    int allOnes = ~0;

    // 1s before position j, then 0s left = 11100000
    // ! This excludes j
    int left = j < 31 ? allOnes << (j + 1) : 0;

    // 1s after position i, right = 00000011
    int right = ((1 << i) - 1);

    // All 1s, except for 0s between i and j. mask = 11100011
    int mask = left | right;
    
    // Clear bits j through i then put m in there
    int n_cleared = n & mask; // Clear bits j through i
    int m_shifted = m << i; // Moves m into correct position

    return n_cleared | m_shifted; // OR them
}

int main () {
    int n = 1024;
    int m = 19;
    int i = 2;
    int j = 6;
    cout << insertion(n, m, i, j) ; // Output = 1100 (decimal) = 10001001100 (binary)
    return 0;
}