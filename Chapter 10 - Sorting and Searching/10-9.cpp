// Sorted Matrix Search

// ! Incomplete, could add the binary search solution

#include <iostream>

using namespace std;

const int m = 5;
const int n = 5;

// NAIVE SOLUTION
bool findElem(int two_d[m][n], int target) {
    int row = 0;
    int row_length = m;
    int col = sizeof(two_d[0]) / sizeof(two_d[0][0]) - 1;

    while (row < row_length && col >= 0) {
        cout << "two_d[" << row << "][" << col <<"]: " << two_d[row][col] << endl;
        if (two_d[row][col] == target) {
            return true;
        } else if (two_d[row][col] > target){
            col--;
        } else {
            row++;
        }
    }
}


int main() {
    int two_d[m][n] = {{1,2,3,4,5}, 
                        {6,7,8,9,10},
                        {11,12,13,14,15},
                        {16,17,18,19,20},
                        {21,22,23,24,25}};
    cout << findElem(two_d, 13);

}