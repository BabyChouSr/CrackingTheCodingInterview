// 1.1 Is Unique

#include <iostream>
#include <string>
#include <map>
#include <bitset>

using namespace std;
int main() {
    //Brute Force Approach O(n^2)
    string test = "ABCDEFGHIabcdefghijk123";
    bool isUnique = true;
    // for (int i = 0; i < test.length() && isUnique; i++) {
    //     for(int j = i + 1; j < test.length() && isUnique; j++) {
    //         if (test[i] == test[j]) {
    //             isUnique = false;
    //         }
    //     }
    // }
    // cout << isUnique << endl;

    // Using Map O(n)
    map<char, bool> hist;
    for (int i = 0; i < test.length() && isUnique; i++) {
        if (hist[test[i]]) {
            isUnique = false;
        }
        hist[test[i]] = true;
    }

    // Using a bitvector reduces space complexity by 8 times since only holds 1 bit while character holds 8 bits
    bitset<128> bits(0);
    for (int i = 0; i < test.length() && isUnique; i++) {
        if(bits[(int)test[i]] > 0) {
            isUnique = false;
        }
        int val = (int)test[i];
        bits[(int)test[i]] = 1;

        // Answer key used bitset's functions:
        // int val = str[i];
        // if (bits.test(val) > 0) {
        //     return false;
        // }
        // bits.set(val);
    } 

    cout << isUnique << endl;
    return 0;
}