// 1.3 URLify

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void URLify(char *given, int strLength) {

    // T: O(n) for each character
    // Caveat: This is not in place, Would need to strip the string
    // string givenURLed = "";
    // for (int i = 0; i < strLength; i++) {
    //     if (given[i] == ' ') {givenURLed += "%20";}
    //     else { givenURLed += given[i];}
    // }
    // return givenURLed;

    // T: O(n) for each character
    // IN PLACE
    int numSpaces = 0;

    //T: Entire Algorithm is O(n)
    // Would need to strip the string
    for (int i = 0; i < strLength; i++) {
        if (given[i] == ' ') {numSpaces++;}
    }

    // while (numSpaces > 0) {
         // Find operation requires O(n)
    //     int locSpace = given.find(" ");
    //     given = given.substr(0, locSpace) + "%20" + given.substr(locSpace + 1, strLength - locSpace + 1);
    //     numSpaces--;
    // }

    // return given;

    // Sample Answer:
    /* Differences: Uses extended length which is important so that you don't have to strip string (just start at end of string)
        Utilizes a character array in order to accomodate the increase in space
    */
    int extendedLen = strLength + 2 * numSpaces;
    int i = extendedLen - 1;
    for (int j = strLength - 1; j >= 0; j--) {
        cout << given[j] << endl;
        if (given[j] != ' ') {
            given[i--] = given[j];
        }
        else {
            given[i--] = '0';
            given[i--] = '2';
            given[i--] = '%';
        }
    }

}

int main() {
    vector <string> test  = {"Mr John Smith   ", "hi bro", "you are cool", "i love you"};
    char str[] = "Mr John Smith  ";
    URLify(str , 13  );
    cout << "urlify(Mr John Smith   ): " << str << endl;
    return 0;
}