// Parens

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string insertCharAt(string word, char c, int i) {
    // Insert at some i location where location where c is at is i + 1
    // cout << word.substr(0, i) + c + word.substr(i, word.length() - i) << endl;
    return word.substr(0, i + 1) + c + word.substr(i + 1, word.length() - i);
}

vector <string> parens(vector <string>& combs, string prefix, int i, int n) {
    if (n == 1) {
        combs.push_back("()");
        return combs;
    }
    vector <string> prevCombs = parens(combs, prefix, i, n -1);
    combs = vector <string> ();
    for (const auto& word: prevCombs) {
        
        i = -1;
        while (word[i] != ')') {
            string newStr = '(' + insertCharAt(word, ')', i);
            combs.push_back(newStr);
            i++;
        }
    }

    return combs;
}


int main() {
    int i = 4;
    vector <string> parentheses = vector <string> ();
    parentheses = parens(parentheses, "", 0, i);
    for (const auto& word: parentheses) {
        cout << word << endl;
    }
    return 0;
}