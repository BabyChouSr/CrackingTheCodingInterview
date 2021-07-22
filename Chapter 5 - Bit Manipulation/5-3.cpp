// Flip Bit to Win

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(b)
// Space Complexity: O(b)
int findLongestSequence(vector<int> seq) {
    int maxSeq = 1;
    for (int i = 0; i < seq.size(); i+=2 ) {
        int zerosSeq = seq[i];
        int onesSeqPrev = i - 1 >= 0 ? seq[i-1] : 0; // Get the right side
        int onesSeqNext = i + 1 < seq.size() ? seq[i+1] : 0; // get the left side

        int thisSeq = 0;

        if (zerosSeq == 1) { // One 0
            thisSeq = onesSeqNext + 1 + onesSeqPrev;
        } else if (zerosSeq > 1) {
            thisSeq = 1 + max(onesSeqPrev, onesSeqNext);
        } else if (zerosSeq == 0) {
            thisSeq = max(onesSeqPrev, onesSeqNext);
        }
        maxSeq = max(thisSeq, maxSeq);
    }
    return maxSeq;
}

vector <int> getAlternatingSequences(int n) {
    vector <int> sequences = vector<int> ();
    
    int searchingFor = 0;
    int counter = 0;

    for (int i = 0; i < sizeof(int) * 8; i++) {
        if ((n & 1) != searchingFor) { // We are starting with 0 so the 0 & 1 == searchingFor (0) at the start and counts all the starting 0s, when there is a 1, then we convert searchingFor to 1
            sequences.push_back(counter);
            searchingFor = n & 1; // Flips 0 to 1 or 1 to 0
            counter = 0;
        }
        counter++;
        n >>= 1; // Logical Shift, look for next bit
    }
    sequences.push_back(counter);
    return sequences;
}

int longestSequence (int x) {
    vector <int> sequences = getAlternatingSequences(x);
    return findLongestSequence(sequences);
}

// Optimal Algorithm
// We don't have to hold onto the entire lengths, don't need extra O(b)
int flipBit(int a) {
    if (~a == 0) return sizeof(int) * 8;

    int currentLength = 0;
    int previousLength = 0;
    int maxLength = 1; // We can always have a sequence of at least one 1
    while (a != 0) {
        if( (a & 1) == 1) { // Current bit is 1
            currentLength++;
        } else if ( (a & 1) == 0) { // Current bit is 0 
            // Update to 0 (if next bit is 0) or currentLength (if next bit is 1)
            previousLength = (a & 2) == 0 ? 0 : currentLength; 
            currentLength = 0;
        }
        maxLength = max(previousLength + currentLength + 1, maxLength);
        a >>= 1;
    }
    return maxLength;
}

int main(){
    int x = 1775;
    cout << flipBit(x);
    return 0;
}