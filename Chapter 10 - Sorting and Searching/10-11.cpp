// Peaks and Valleys

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> 

using namespace std;

// Sort and then create alternating sequence by swapping each pair 
// Timing is O(N log N) + O(n) for the sorting + swapping phase 
void sortPeaksValleys(vector <int> & arr) {
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i+=2) {
        swap(arr[i], arr[i-1]);
    }
}

// Basic gist of the algorithm is to find every three elements and swap the center element with the largest adjacent element
// ex. 0 - 1 - 2  -> 0 - 2 - 1 to create the peak in the middle 
int maxIndex(vector <int> arr, int a, int b, int c) {
    int aValue = 0 <= a && a < arr.size() ? arr[a] : numeric_limits<int>::min();
    int bValue = 0 <= b && b < arr.size() ? arr[b] : numeric_limits<int>::min();
    int cValue = 0 <= c && c < arr.size() ? arr[c] : numeric_limits<int>::min();
    int maxValue = max(aValue, max(bValue,cValue));
    if (maxValue == aValue) {return a;}
    else if (maxValue == bValue) {return b;}
    else return c;

}

void sortPeaksValleys2(vector <int> & arr) {
    for (int i = 1; i < arr.size(); i += 2) {
        if (i != maxIndex(arr, i - 1, i, i + 1)) {
            swap(arr[i], arr[maxIndex(arr, i - 1, i, i + 1)] );
        }
    }
}


int main() {
    vector <int> arr = {5,3,1,2,3};
    sortPeaksValleys2(arr);
    for (const auto& num: arr) {
        cout << num << ", " << endl;
    }
    return 0;
}