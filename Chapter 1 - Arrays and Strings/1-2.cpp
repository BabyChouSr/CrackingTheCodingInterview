// Check Permutation

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPermutation_map(string test1, string test2) {
    if (test1.length() != test2.length()) {return false;}

    // could technically reduce this down to just an array and then 
    // use index that corresponds to the character (reduces the space needed)
    map<char, int> hist1;
    map<char, int> hist2;

    // T: O(n), S: O(n)
    // Utilizing maps and then comparing histograms
    for (int i = 0; i < test1.length(); i++) {
        if (hist1[test1[i]]) { 
            hist1[test1[i]]++;
        }
        hist1[test1[i]] = 1;
        if (hist2[test2[i]]) {
            hist2[test2[i]]++;
        }
        hist2[test2[i]] = 1;

    }
    return hist1 == hist2;
}

bool checkPermutation_sort(string test1, string test2) {
    if (test1.length() != test2.length()) {return false;}

    //T: O(n log(n)) because it usese comparision-based sorting
    sort(test1.begin(), test1.end());
    sort(test2.begin(), test2.end());
    return test1 == test2;
}

int main() {

    vector<string> tests = {"hello123", "elloh321", "123", "boom", "e1h3lo2l"};

    for(int i = 0; i < tests.size() - 1; i++) {
        cout << checkPermutation_map(tests[0], tests[i+1]) << endl;
    }

    for(int i = 0; i < tests.size() - 1; i++) {
        cout << checkPermutation_sort(tests[0], tests[i+1]) << endl;
    }
    return 0;
}