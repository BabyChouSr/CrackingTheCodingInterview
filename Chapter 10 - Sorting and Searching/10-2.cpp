//Group Anagrams

#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <map>

using namespace std;

bool checkAnagram(string x, string y) {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    return x == y;
}

// Time complexity is at worst O(n^2 + n * log(s)) where n is the number of strings + s is the number of characters per string
// Space Complexity requires another O(N) for sorted 
// ! NOT WORKING
vector <string> sortAnagrams(vector <string> arr) {
    vector <string> sorted = vector <string> ();
    while (!arr.empty()) { // Are there more strings to compare?
        string toCompare = arr.back();
        for (int i = 0; i < arr.size(); i++) { // Find an anagram that corresponds to this -- THIS does not work if we do not find a match right?? would need to keep track of all anagrams 
            if (checkAnagram(arr[i], toCompare)) {
                sorted.push_back(arr[i]);
                sorted.push_back(arr.back());
                arr.erase(arr.begin() + i);
                arr.pop_back();
            }
        }
    }
    return sorted;
}


// Additional Space is O(n * s) for the map
// Time Complexity: O(n * s log(s) + n) where n is the total number of strings and s is the number of characters in the string
void sortAnagrams2(vector <string>&arr) {
    map <string, vector <string>> anagrams;
    for (const auto& word: arr) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        if (anagrams.find(sortedWord) == anagrams.end()) { // can't find it
            vector <string> words;
            words.push_back(word);
            anagrams[sortedWord] = words;
        } else {
            anagrams[sortedWord].push_back(word);
        }
    }

    int index = 0;
    for (const auto listOfWords: anagrams) { // adds the anagrams into the original array inplace
        for (const auto& aWord: listOfWords.second) {
            arr[index] = aWord;
            index++;
        }
    }

}

int main(){
    vector <string> anagrams = {"was", "care" , "saw", "race", "sonder", "ondser"};
    // anagrams = sortAnagrams(anagrams);
    sortAnagrams2(anagrams);
    for (const auto& word: anagrams) {
        cout << word << endl;
    }
    return 0;
}