// Sorted Merge

#include <iostream>
#include <vector>

using namespace std;

void sortedMerge(vector <int> &a, vector <int> &b, int sizeA, int sizeB) {
    int indexMerged = sizeA + sizeB - 1;
    int indexA = sizeA - 1;
    int indexB = sizeB - 1;

    while (indexB >= 0) {
        if(indexA >=0 && a[indexA] > b[indexB]) {
            a[indexMerged] = a[indexA];
            indexA--;
        } else {
            a[indexMerged] = b[indexB];
            indexB--;
        }
        indexMerged--;
    }
}

int main() {
    vector <int> a = vector <int> ();
    a.push_back(2);
    a.push_back(4);
    a.push_back(6);
    a.push_back(8);
    a.push_back(10);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    vector <int> b = vector <int> ();
    b.push_back(1);
    b.push_back(3);
    b.push_back(5);
    sortedMerge(a,b,5,3);
    for (const auto& elem: a) {
        cout << elem << endl;
    }
    return 0;
}