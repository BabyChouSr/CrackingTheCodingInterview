// Stack of Boxes

#include <iostream>
#include <vector>
#include <limits> 

using namespace std;


// Thought was that we have different levels and we try each combination as the box at certain level = index
// Basically would start with any box at a certain level and then use the mod operator to randomly pick the next one
// ! NOT WORKING BUT SIMILAR FRAMEWORK
int longestStack(vector <int> width, vector <int> height, vector <int> depth, int prevWidth, int prevHeight, int prevDepth, int currStackLength, int index, int currMax) {
    // Make sure not out of bounds
    for (int j = 0; j < width.size() ; j++) {
        int currWidth = width[j] ;
        int currHeight = height[j];
        int currDepth = depth[j];

        if (currWidth < prevWidth || currHeight <  prevHeight || currDepth < prevDepth) {
            cout << "LEVEL: " << index << ", curr height: " << currHeight << ", prev height: " << prevHeight << endl;
            int currStackLength = longestStack(width, height, depth, currWidth, currHeight, currDepth, currStackLength + 1, index + 1, currMax);
            currMax = currStackLength > currMax ? currStackLength : currMax;
        }
    }
    return currMax;
}

int main() {
    vector <int> width = {1,2,3,4,5};
    vector <int> height = {1,2,3,4,5};
    vector <int> depth = {1,2,3,4,5};

    cout << longestStack(width, height, depth, numeric_limits<int>::max(), numeric_limits<int>::max(), numeric_limits<int>::max(), 0, 0, 0);
    return 0;
}