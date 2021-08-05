// Triple Step

#include <iostream>
#include <map>

using namespace std;

// We approach this question with a top-down approach where we subtract the number of steps as we go
// Default cases are defined with steps < 0 being 0 since that means we overstep and it won't work
// steps == 0 means that we are on the right spot
// Other than that, we add up all the possible combinations with possible steps of 1, 2, 3
// Time Complexity : O(3^n) since we branch into 3 different recursive calls
int possibleSteps(int steps) {
    if (steps < 0) {
        return 0;
    }
    else if (steps == 0) {
        return 1;
    }
    return possibleSteps(steps - 1) + possibleSteps(steps - 2) + possibleSteps(steps - 3);
}

// Memoize the process
int memoizedPossibleSteps(int steps, map<int, int> & cache) {
    if (steps < 0) {
        cache[steps] = 0;
        return 0;
    }
    else if (steps == 0) {
        cache[steps] = 1;
        return 1;
    }
    if (cache.find(steps) == cache.end()) {
        cache[steps] = memoizedPossibleSteps(steps - 1, cache) + memoizedPossibleSteps(steps - 2, cache) + memoizedPossibleSteps(steps - 3, cache);
    }
    return cache[steps];
}


int main () {
    int steps = 30;
    map <int, int> cache;
    cout << memoizedPossibleSteps(steps, cache);
    return 0;
}