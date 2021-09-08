// Sparse Search

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binSearch(vector <string> arr, int low, int high, string target) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) /2;
    
    // Since there is a change that mid is empty, we have to find the closest non-empty element
    if (arr[mid].length() == 0) {
        bool found = false;
        int next = -1;
        int left = mid - 1;
        int right = mid + 1;
        while (!found) {
            if (left < low && right > high) { // make sure to have this so binary search works on the boundaries
                found = true; // hit boundary
            }
            if (left >= 0) {
                if (arr[left].length() > 0) {
                    next = left;
                    found = true;
                }
            }
            else if (right < arr.size()) {
                if (arr[right].length() > 0) {
                    next = right;
                    found = true;
                }
            }
            left -= 1;
            right +=1;
        }
        mid = next ? next >= 0 : mid;
    }

    if (arr[mid] == target) {return mid;}
    if (arr[mid] > target) {
        return binSearch(arr, low, mid - 1, target);
    } 
    else {
        return binSearch(arr, mid + 1, high, target);
    }
}

int main() {
    vector <string> arr = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout << binSearch(arr, 0, arr.size() - 1, "at");
    return 0;
}