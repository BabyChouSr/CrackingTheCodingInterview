// Pairwise Swap

#include <iostream>

using namespace std;

int pairwiseSwap(int x) {
    // First part for odd bits to shift right, using mask 1010101010
    // Second part for even bits and shift left, using mask 0101010101
    // Then, add both parts
    return (( (x & 0xaa) >> 1) | (x & 0x55) << 1);
}

int main() {
    cout << pairwiseSwap(55);
    return 0;
}