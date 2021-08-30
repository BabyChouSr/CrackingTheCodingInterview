// Recursive Multiply

#include <iostream>
#include <map> 

using namespace std;



int recursiveMultiplyHelper(int x, int y) {
    if (x == 0) {
        return 0;
    } else if (x == 1) {
        return y; 
    }

    // Compute half. If uneven, then we need to compute the other half separately. If even, double it by doing side1 + side 2
    int s = x >> 1; // Divide by 2
    int side1 = recursiveMultiplyHelper(s, y); // Count half the squares 
    int side2 = side1; 

    // We have this for if x is odd because then s + s != x -> would have to do x - s + s = x where x - s is odd
    if (x % 2 == 1) { 
        side2 = recursiveMultiplyHelper(x - s, y);
    }
    return side1 + side2;
}

int recursiveMultiplyHelper2(int x, int y, map<int, int> cache) {
    if (x == 0) {
        return 0;
    } else if (x == 1) {
        return y;
    } else if (cache.find(x) != cache.end()) {
        return cache[x];
    }

    int s = x >> 1;
    int side1;
    int side2;
    side1 = recursiveMultiplyHelper2(s, y, cache);
    side2 = side1;
    if (x % 2 == 1) {
        // The change to do the bottom cache method is because then we don't have to recalculate for odd numbers
        // since odd numbers = the even numbers + bigger. ex. 31 = 16 + 15 before but instead we can just do 31 = 15 * 2 + 31
        // so we don't have to recursively drill down for both odd and even
        // side2 = recursiveMultiplyHelper2(x-s, y, cache);
        cache[x] = side1 + side2 + y;
        return cache[x];
    }
    cache[x] = side1 + side2;
    return cache[x];
}

int recursiveMultiply(int x, int y) {
    int smaller = x > y ? y : x;
    int bigger = x > y ? x : y;
    map <int, int> cache;
    return recursiveMultiplyHelper2(smaller, bigger, cache);
}

int main() {
    cout << recursiveMultiply(9,6);
    return 0;
}