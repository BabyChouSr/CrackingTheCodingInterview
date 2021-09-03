// Coins 

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// This way double counts solutions since the order you pick coins doesn't matter and this doesn't account for that
int coins(int n, int count) {
    if (n < 0) {
        return count;
    }
    if (n == 0) {
        return 1;
    }

    return coins(n - 1, count) + coins (n - 5, count) + coins(n - 10, count) + coins(n - 25, count);

}


// n = total number of cents
// denoms = [25,10,5,1] 
// index = which coin is being used
// we can cache when the coins used matches the n - total number of cents and index
int coins2(int n, vector <int> denoms, int index, map < pair<int, int> , int > cache) { 
    int coin = denoms[index];

    if(cache.find(make_pair(n, index)) != cache.end()) {
        return cache[make_pair(n, index)];
    }

    if (index == denoms.size() - 1) {
        int remaining = n % coin;
        return remaining == 0 ? 1 : 0;
    }

    int ways = 0;
    for (int amount = 0; amount <= n; amount += coin) {
        ways += coins2(n - amount, denoms, index + 1, cache);
    }
    cache[make_pair(n, index)] = ways;
    return ways;
}

int main (){ 
    int amt = 100;
    map <pair<int, int>, int> cache;
    cout << coins2(amt, {25,10,5,1}, 0, cache);
    return 0;
}