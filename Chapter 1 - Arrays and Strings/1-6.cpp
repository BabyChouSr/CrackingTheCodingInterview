// String Compression

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string stringCompression (string str) {
    // issue with this is that it 1. requires the vector but isn't that useful since we are looking at repeated characters
    // not character as a whole
    vector <int> counter(128);
    string newString = "";
    for (int i = 0; i < str.length(); i++) {
        int val = (int) str[i];
        counter[val]++;
    }
    for (int i = 0; i < counter.size(); i++) {
        if (counter[i] > 0) {
            newString += (char) i;
            newString += to_string(counter[i]);
        }
    }
    newString = newString.length() > str.length() ? str : newString;
    return newString;

}

string stringCompression2 (string str) {
    // Could combine the two loops above -> fixes the repeated character problem

    string newstr = "";
    int count = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i-1]) {
            count++;
        } else {
            newstr += str[i-1];
            newstr += to_string(count);
            count = 1;
        }
        if (newstr.length() > str.length()) {
            return str;
        }
    }
    // need an extra for the very last character because usually would not run for last char
    newstr += str[str.length()-1];
    newstr += to_string(count);
    if (newstr.length() > str.length()) {
            return str;
        }
    return newstr;
}

int main () {

    vector <string> test = {"aabccccaaa", "abc", "ABSCAasdasdddddddddddddddddddd"};
    for (const auto& str: test) {
        cout << stringCompression2(str) << endl;
    }
    return 0;
}