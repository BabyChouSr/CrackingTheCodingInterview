// One Away

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool oneAway(string one, string two) {
    int countOff = 0;
    // insert a character
    int j = 0;
    if (one.length() > two.length()) {
        for (int i= 0; i < one.length(); i++) {
            if (one[i] == two[j]) {
                j++;
            }
            else {
                countOff++;
            }
        }
        return countOff <= 1;
    }
    // remove a character (symmetric case to inserting character but with other string)
    if (one.length() < two.length()) {
        for (int i= 0; i < two.length(); i++) {
            if (one[i] == two[j]) {
                j++;
            }
            else {
                countOff++;
            }
        }
        return countOff <= 1;
    }
    // replace a character
    if (one.length() == two.length()) {
        countOff = 0;
        for(int i = 0; i< one.length();i++) {
            if(one[i] != two[i]) {countOff++;}
        }
        return countOff <= 1;
    }
    return false;
}

bool oneAway2(string one, string two) {
    // Need to optimize to be able to do all three checks in one pass
    int countOff = 0; 
    int j = 0;
    int i = 0;

    if (labs(two.length() - one.length()) > 1) {return false;}
    while (i < one.length() && j < two.length()) {
        // cout << i << j << endl;
        if (one[i] != two[j]) {
            countOff++; 
            if (one.length() > two.length()) {
                i++;
            }
            if (one.length() ==  two.length()) {
                i++;
                j++;
            }
            if (one.length() < two.length()) {
                j++;
            }
        }
        else {
            i++;
            j++;
        }
    }
    return countOff <= 1;
}

int main() { 
    vector<string> test = {"pale", "ple", "pales", "pale", "bale", "bake", "pale"};
    for (int i= 0; i < test.size() -1; i++) {
        cout << oneAway2(test[i], test[i+1]) << endl;
    }
    return 0;
}