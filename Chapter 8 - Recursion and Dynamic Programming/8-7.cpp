// Permutation without Dups

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string insertCharAt(string s, char c, int j) {
    return  s.substr(0, j) + c + s.substr(j, s.size() - j);
}

// This is the first approach where you build from permutations of first n-1 characters
// You have a string "abc" and you want to add "d" so you add "d" to each location possible:
// "dabc" - "adbc" - "abdc" - "abcd"
// Do this for all permutations of "abc" and recursively follow this train of thought
vector <string> permutations(vector<string> & perms, string s) {
    perms = vector<string> ();
    if (s.length() == 0) {
        perms.push_back("");
        return perms;
    }

    char first = s[0];
    string remainder = s.substr(1, s.size() - 1);
    vector <string> words = permutations(perms, remainder);
    for (const string word: words) {
        for (int i = 0; i <= word.length(); i++) {
            string s = insertCharAt(word, first, i);
            perms.push_back(s);
        }
    }
    return perms;
}

// Another approach is to build from permutations of all n - 1 character substrings
// Check Approach 2 of CTCI 
// ! Not Working
vector <string> permutations2(vector <string> & perms, string remainder) {
    perms = vector <string>(); // ! Important Line or else it keeps everything from before (using references)
    int len = remainder.length();
    if (len == 0) {
        perms.push_back("");
        return perms;
    }

    for (int i = 0; i < len; i++) {
        string before = remainder.substr(0, i);
        string after = remainder.substr(i + 1, len - (i+1));
        vector <string> partials = permutations2(perms, before + after);
        for (const auto& s: partials) {
            perms.push_back(remainder[i] + s);
        }
    }
    return perms;
}

// Sending the prefix down the stack instead of permutations up the stack
// Doesn't work either
void permutations3helper(string prefix, string remainder, vector <string> & perms) {
    if (remainder.length() == 0) {perms.push_back(prefix);}

    int len = remainder.length();
    for (int i = 0; i < len; i++) {
        string before = remainder.substr(0, i);
        string after = remainder.substr(i+1, len - (i+1));
        char c = remainder[i];
        permutations3helper(prefix + c, before + after, perms);
    }
}

vector <string> permutations3(string str) {
    vector <string> perms = vector <string> ();
    permutations3helper("", str, perms);
    return perms;
}



int main() {
    string s = "abcd";
    vector <string> perms = vector <string> ();
    perms = permutations(perms, s);
    for (const auto & s: perms) {
        cout << s << endl;
    }
    return 0;
}