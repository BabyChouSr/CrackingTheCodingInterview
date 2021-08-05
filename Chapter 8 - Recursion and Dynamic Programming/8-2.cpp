// Robot in a grid

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Point {
    int row;
    int col;
    Point() : row(0), col(0) {}
    Point(int row, int col) : row(row) , col(col) {}
};

// Counts the number of ways to go from one corner to the other regardless of potential points that don't work
int robotInAGrid(int currRow, int currCol) {
    if (currRow < 0 || currCol < 0) {
        return 0;
    }
    else if (currRow == 0 && currCol == 0) {
        return 1;
    } else {
        return robotInAGrid(currRow - 1, currCol) + robotInAGrid(currRow, currCol - 1);
    }
}

bool getPath(int matrix[5][5] , int row, int col, vector <Point*>& path) {
    if (row < 0 || col < 0 || matrix[row][col] == -1) {
        cout << matrix[row][col] << endl;
        return false;
    }

    bool isAtOrigin = (row == 0 && col == 0);

    if (isAtOrigin || (getPath(matrix, row, col -1, path) || getPath(matrix, row - 1, col, path))) {
        Point* p = new Point(row, col);
        path.push_back(p);
        return true;
    }
    
    return false;

    }

// Adding a list of failed points so that we don't have to go down that path again
bool getPath2(int matrix[5][5] , int row, int col, vector <Point*>& path, unordered_set <Point*> & failedPoints) {
    if (row < 0 || col < 0 || matrix[row][col] == -1) {
        cout << matrix[row][col] << endl;
        return false;
    }

    Point* p = new Point(row, col);

    // check if the point is in the failedPoints so we don't have to have more recursive calls
    if (failedPoints.find(p) != failedPoints.end()) {
        return false;
    }

    bool isAtOrigin = (row == 0 && col == 0);

    if (isAtOrigin || (getPath2(matrix, row, col -1, path, failedPoints) || getPath2(matrix, row - 1, col, path, failedPoints))) {
        path.push_back(p);
        return true;
    }
    
    // cache result
    failedPoints.insert(p);
    return false;

}

vector<Point*> getPath(int matrix[5][5], int rows, int cols) {
    vector <Point*> path;
    unordered_set <Point*> failedPoints;

    if (getPath2(matrix, rows - 1, cols - 1, path, failedPoints)) {
        return path;
    }

    return path;
}

int main () {
    int rows = 5;
    int cols = 5;
    int matrix[5][5] = {
        {1,1,1,1,1},
        {1,1,1,-1,1},
        {-1,1,-1,-1,-1},
        {-1,1,1,-1,-1},
        {-1,1,1,1,1}
    };
    vector <Point*> path2 = getPath(matrix, rows, cols);
    for (int i = 0; i < path2.size(); i++) {
        cout << "[" << path2[i]->row << "]" << "[" << path2[i]->col << "]" << endl;
    }
    return 0;
}