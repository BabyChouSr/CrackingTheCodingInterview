// Power Set

#include <iostream>
#include <vector>

using namespace std;

// The approach for this one is to basically bruteforce it starting from the first element and adding all other ones following it
vector<vector<int>> powerSet(vector <int> s, vector<vector<int>> & subsets, int index) {
    if (index >= s.size()) {
        return subsets;
    }
    vector <int> entire;
    for (int i = index; i < s.size(); i++) {
        entire.push_back(s[i]);
        subsets.push_back(entire);
    }
    return powerSet(s, subsets, index +1);
}

// This approach generates the total number of solutions = 2^n where n is the size of the array
// Then, we convert the binary representation of those solutions into sets referring to 1 where the number is in the set
// and 0 means that the number is not in the set

vector<int> convertIntToSubset(vector<int> s, int bits) {
    vector<int> subset;
    int index = 0;
    for (int k = bits; k > 0; k >>=1) {
        if (k & 1 == 1) {
            subset.push_back(s[index]);
        }
        index++;
    }
    return subset;
}

vector<vector<int>> powerSet2(vector<int> s) {
    vector<vector<int>> allSubsets;
    int max = 1 << s.size(); // Computes 2^n
    for(int k = 0; k < max; k++) {
        vector<int> subset = convertIntToSubset(s, k);
        allSubsets.push_back(subset);
    }
    return allSubsets;
}

int main() {
    vector <int> s = {1,2,3,4,5};
    vector<vector<int>> subsets;
    // subsets = powerSet(s, subsets, 0);
    subsets = powerSet2(s);
    for (const auto& set: subsets) {
        for (const auto& num: set) {
            cout << num << ", ";
        }
        cout << endl;
    }
    return 0;
}