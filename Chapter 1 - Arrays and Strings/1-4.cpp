// Palindrome Permutation

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool palindromePermutation(string str) {
    // IDEA: put string into vector that counts number of instances of letter
        // must end up being even, at most can have one odd

    if (str.length() == 1) {return true;}
    vector <int> letters(128);

    // 1. T = O(n)

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            int val = (int) tolower(str[i]);
            letters[val]++;
        }
    }

    int numOdd = 0;
    for (const auto count: letters) {
        if (count % 2 != 0) {numOdd++;}
        if (numOdd > 1) {return false;}
    }
    

    return true;
}

bool palindromePermutation2(string str) {
    // Optimize by combining the two for loops into just one
        // by counting the number of Odds while adding into the vector
    if (str.length() == 1) {return true;}
    vector <int> letters(128);
    int oddCount = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            int val = (int) tolower(str[i]);
            letters[val]++;

            // 1st Approach was to count the frequency and then check for modulus 
                // ISSUE: because 1 could be considered odd we can't just say "Odd Appeared", must wait for more
                // therefore, we have to come up with approach that doesn't use flag
            if (letters[val] % 2) { // Notice how we use binary states
                oddCount++;
            } else {
                oddCount--;
            }
        }
    }
    return (oddCount <= 1);
}

// int getCharIndex( char c )
// {
//     int idx = -1;
//     if ( c >= 'a' && c <= 'z' )
//     {
//         idx = c - 'a';
//     }
//     else if ( c >= 'A' && c <= 'Z' )
//     {
//         idx = c - 'A';
//     }
//     return idx;
// }

int toggle(int bitVector, int id) {
    if (id < 0) {
        return bitVector;
    }
    int mask = 1 << id;  // shifts id number of places for the number 1 so it's 2^id power
    // cout << "mask(" << id << "): " << mask << endl;
    // if bit is not set
    if ((bitVector & mask) == 0) {
        bitVector |= mask;
    } else { // if bit is set then clear which serves as a toggle essentially
        bitVector &= ~mask;
        // could also toggle so bitvector ^= mask;
    }
    return bitVector;
}

bool isExactlyOneBitSet(int bitVector) {
    return ((bitVector & (bitVector - 1 )) == 0);
}

bool palindromePermutation3(string str) {
    // Optimizing by not even using integers anymore, we notice that binary states are used which is perfect for 
        // a bit vector where you toggle states
    if (str.length() == 1) {return true;}
    int bitVector = 0; // using an integer as the bitVector
    int id = 0;
    for (const auto& character: str) {
        if (isalpha(character)) {
            id = (int) tolower(character);
            // cout << id << endl;
            bitVector = toggle(bitVector, id);
        }
    }
    return (bitVector == 0 || isExactlyOneBitSet(bitVector));
}


int main() {
    vector<string> test = {"what the heck", "you are awesome", "tact coa"};
    for (const auto testString : test) {
        cout << testString << " : " << palindromePermutation3(testString) << endl;
    }
    return 0;
}