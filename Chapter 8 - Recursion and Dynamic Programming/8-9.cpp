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

// Idea behind this is to always add a left paranthesis at the first index 
// ONLY add a right paranthesis if the location to add at is not a ')'
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

// Cracking the coding interview uses similar approach just without the while loop and 
// the need for a previous combo of words
// Always in the correct order because we first do the left paren then the right paren and can create all combos through recursion
void addParens(vector <string> & combs, int index, int leftRem, int rightRem, string curr) {
    if (leftRem < 0 || rightRem < leftRem) {
        return;
    }
    if (leftRem == 0 && rightRem == 0) {
        combs.push_back(curr);
    }

    else {
        curr[index] = '(';
        addParens(combs, index + 1, leftRem - 1, rightRem, curr);

        curr[index] = ')';
        addParens(combs, index + 1, leftRem, rightRem - 1, curr);
    }
}

vector <string> generateParens(int n) {
    vector <string> combs = vector <string> ();
    string str = "";
    for (int i = 0; i < n * 2; i++) {
        str += " ";
    }
    addParens(combs, 0, n, n, str);
    return combs;
}

int main() {
    int i = 3;
    vector <string> parentheses = vector <string> ();
    // parentheses = parens(parentheses, "", 0, i);
    // for (const auto& word: parentheses) {
    //     cout << word << endl;
    // }

    vector <string> parantheses2 = generateParens(i);
    for (const auto& word: parantheses2) {
        cout << word << endl;
    }
    return 0;
}