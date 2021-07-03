// Rotate Matrix

#include <iostream>

using namespace std;

const size_t N = 5;

void printArray(int twod[N][N]) {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            cout << twod[i][j] << ", ";
        }
        cout << "\n";
    }
}

void rotate_matrix(int twod[N][N]) {
    // indices were kind of tricky....
    // also the end condition for the second loop tripped me up for a little bit, should remember to trace end conditions too
    for (int i = 0; i < N/2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int rowOneVal = twod[i][j];
            int colOneVal = twod[N - j - 1][i];
            int colLastVal = twod[j][N - i - 1];
            int rowLastVal = twod[N - i - 1][N - j - 1];
            twod[i][j] = twod[N - j - 1][i]; // 1st Col -> 1st Row
            twod[j][N - i - 1] = rowOneVal; // 1st Row -> Last Col
            twod[N - i - 1][N - j - 1] = colLastVal; // Last Col -> Last Row
            twod[N - j - 1][i] = rowLastVal; // last Row -> 1st Col
        }
    }

}

int main() {
    int twod[N][N] = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        21, 22, 23, 24, 25
    };
    rotate_matrix(twod);
    printArray(twod);
    return 0;
}