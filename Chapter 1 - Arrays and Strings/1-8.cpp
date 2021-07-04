// Zero Matrix

#include <iostream>
#include <vector>

using namespace std;

const int M = 5;
const int N = 5;

void printArray(int twod[N][N]) {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            cout << twod[i][j] << ", ";
        }
        cout << "\n";
    }
}

void printArrayBool(bool twod[N][N]) {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            cout << twod[i][j] << ", ";
        }
        cout << "\n";
    }
}

void zeroMatrix(int twod[M][N]) {
    bool zero[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!twod[i][j]) {
                zero[i][j] = true;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (zero[i][j] == true) {
                for (int k = 0; k < N; k++) {
                    twod[i][k] = 0;
                    twod[k][j] = 0;
                }
            }
        }
    }
}

void zeroMatrix2(int twod[M][N]) {
    vector<bool> rows(M);
    vector<bool> cols(N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (twod[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    // optimization is to reduce to space complexity of O(M+N) instead of O(M*N)

    for (int i = 0; i < rows.size(); i++) {
        if (rows[i] == true) {
            for (int j = 0; j < M; j++) {
                twod[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < rows.size(); i++) {
        if (cols[i] == true) {
            for (int j = 0; j < N; j++) {
                twod[j][i] = 0;
            }
        }
    }
}

void zeroMatrix3(int twod[M][N]) {
    bool firstRow = false;
    bool firstCol = false;

    for (int i = 0; i < N; i++) {
        if (twod[0][i] == 0 ) { firstRow = true; break;}
    }
    
    // check the rest of the rows
    for (int i = 1; i < M; i++) {
        bool nullifyRow = false;
        for (int j = 0; j < N; j++) {
            if (twod[i][j] == 0) {
                twod[0][j] = 0;
                nullifyRow = true;
            }
        }
        if (nullifyRow) {
            for (int k = 0; k < N; k++) {
                twod[i][k] = 0;
            }
        }
    }

    for (int i = 0; i < N; i++){
        if (twod[0][i] == 0) {
            for (int j = 0; j < M; j++) {
                twod[j][i] = 0;
            }
        }
    }
    if (firstRow) {
        for (int i = 0; i<N;i++) {
            twod[0][i] = 0;
        }
    }

}
int main(){

    int twod[M][N] = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10,
        11, 12, 0, 14, 15,
        16, 17, 18, 19, 0,
        0, 22, 23, 24, 25
    };
    zeroMatrix3(twod);
    printArray(twod);

    return 0;
}