// Towers of Hanoi

#include <iostream>
#include <vector>

using namespace std;

// X = 0 Source
// Z = 1 Temp
// Y = 2 Destination
// Previously, I separated into base cases 1 and 2 and then had 3+ case, but can simplify
void sortDisks(int N, vector <int> & src, vector <int> & temp, vector <int> & dest) {
    if (N == 1) {
        int back = src.back();
        src.pop_back();
        dest.push_back(back);
        return;
    } else if (N == 2) {
        int first = src.back();
        src.pop_back();
        int second = src.back();
        src.pop_back();
        temp.push_back(first);
        dest.push_back(second);
        dest.push_back(temp.back());
        temp.pop_back();
        return;
    } 
    if (N > 2) {
        sortDisks(N - 1, src, dest, temp);
        dest.push_back(src.back());
        src.pop_back();
        sortDisks(N - 1, temp, src, dest);
    }
}

int main(){
    vector<vector<int>> towers;
    vector <int> emptyV = vector <int> ();
    towers.push_back(emptyV);
    towers.push_back(emptyV);
    towers.push_back(emptyV);
    towers[0].push_back(5);
    towers[0].push_back(4);
    towers[0].push_back(3);
    towers[0].push_back(2);
    towers[0].push_back(1);
    sortDisks(towers[0].size(), towers[0], towers[1], towers[2]);
    for (const auto& tower: towers) {
        cout << "Tower: " << endl;
        for (const auto& num: tower) {
            cout << num << ", ";
        }
        cout << endl;
    }
    return 0;
}