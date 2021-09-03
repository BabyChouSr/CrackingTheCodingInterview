// Permutations with Duplicates
// Similar case to before but you have to check if a string is already in list already since not every possible combination is unique


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map <char, int> buildFreqTable(string s) {
    map <char, int> freqTable;
    for (char c: s) {
        if (freqTable.find(c) == freqTable.end()) {
            freqTable[c] = 1;
        }
        else {
            freqTable[c]++;
        }
    }
    return freqTable;
}

void printPerms(map <char, int> & freqTable, string prefix, int remaining, vector <string> & result) {
    if (remaining == 0) {
        result.push_back(prefix);
        return;
    }

    for (map<char, int>::iterator it = freqTable.begin(); it != freqTable.end(); it++) {
        char c = it->first;
        int count = it->second;
        if (count > 0) {
            freqTable[c] = count - 1;
            printPerms(freqTable, prefix + c, remaining -1, result);
            freqTable[c] = count;
        }
    }
}

vector <string> printPerms(string s) {
    vector<string> result = vector<string>();
    map <char, int> freqTable = buildFreqTable(s);
    printPerms(freqTable, "", s.length(), result);
    return result;
}

int main() {
    string s = "aaaabcd";
    vector <string> perms = vector <string> ();
    perms = printPerms(s);
    // permutations(perms, s, 0, s.length());
    for (const auto& str: perms) {
        cout << str << endl;
    }
    return 0;
}