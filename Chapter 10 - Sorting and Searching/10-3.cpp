// Search in Rotated Array

#include <iostream>
#include <vector>

using namespace std;


// Operate under assumption that it is rotated at least once
// Issue with this algorithm is it still has a linear portion, need to combine
int searchRotatedArr(vector <int> arr, int num) {

    int high = arr.size();
    int low = 0;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) {
            break;
        }
        low = i;
    }

    while (low <= high) {
        int mid = (low + high) /2;
        if (arr[mid] == num) {
            return mid;
        }
        if (arr[mid] < num) {
            low = mid + 1;
        } else {
            high = mid -1;
        }
    }
}

// Time Complexity is O(log N)
int searchRotatedArr2(vector <int> arr, int low, int high, int num) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    if (arr[mid] == num) {
        return mid;
    }

    if (arr[mid] > arr[low]) { // Assume Left Side Ordered
        if (num >= arr[low] && arr[mid] > num) {
            return searchRotatedArr2(arr, low, mid - 1, num);
        } else {
            return searchRotatedArr2(arr, mid + 1, high, num);
        }
    }
    else if (arr[mid] < arr[high]) {
        if (num <= arr[high] && arr[mid] < num) {
            return searchRotatedArr2(arr, mid + 1, high, num);
        } else {
            return searchRotatedArr2(arr, low, mid - 1, num);
        }
    }
    else {
        int location = -1;
        if (arr[mid] == arr[low]) {
            location = searchRotatedArr2(arr, mid + 1, high, num);
        }
        if (location == -1 && arr[mid] == arr[high]) { // If could not find on the right side then search left
            location = searchRotatedArr2(arr, low, mid - 1, num);
        }
        return location;
    }
}

int main(){
    vector <int> arr = {15,16,19,20,25,1,3,4,5,7,10,14};
    cout << searchRotatedArr2(arr, 0, arr.size() - 1, 5);
    return 0;
}