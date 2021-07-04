// String Rotation
// String is a rotation if it is a substring of another string concatenated to itself
// example s1 = "waterbottle", and s2 = "erbottlewat", clearly s2 is rotation of s1.
// lets say s1 = xy ==> wat + erbottle
// similarly s2 = yx ==> erbottle + wat
// Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
// So if a string is formed by rotation of another string, it will always be substring of concatenated original string to itself.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isRotation(string s1, string s2) {
    if (s1.length() != s2.length()) {return false;}
    string concatS1 = s1 + s1;
    if (concatS1.find(s2) != string::npos) {
        return true;
    }
    return false;
}

int main() {
    string s1 = "erbottlewat";
    string s2 = "waterbottle";
    cout << isRotation(s1,s2) << endl;
    return 0;
}