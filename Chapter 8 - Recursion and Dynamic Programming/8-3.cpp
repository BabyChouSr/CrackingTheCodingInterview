// Magic Index

#include <iostream>
#include <vector>

using namespace std;



// This is an O(N) algorithm but we want to do better
int magicIndex(vector <int> arr) {
    for (int i  = 0; i < arr.size(); i++) {
        if (i == arr[i]) {
            return i;
        }
    }
    return -1;
}


// This is an O(log N) algorithm 
int magicIndex2(vector <int> arr, int index) {
    if (index < 0 || index >= arr.size()) {
        return -1;
    }
    if (arr[index] == index) {
        return index;
    }
    if (arr[index] > index) {
        return magicIndex2(arr, index/2);
    }
    else if (arr[index] < index) {
        return magicIndex2(arr, index + index/2);
    }
}

int main () {
    vector <int> sorted = {1,2,3,4,5,6,6,8,9,10,11,12,13,14,15};
    cout << magicIndex(sorted);
    return 0;
}