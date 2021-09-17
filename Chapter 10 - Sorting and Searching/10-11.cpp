// Rank from Stream

#include <iostream>
#include <vector>

using namespace std;


struct RankedVector {
    vector <int> hist;
    RankedVector() {}
    
    // Approach is to create histogram and then add up all the instances that is less than or equal to the number
    RankedVector (vector <int> arr) {
        hist = vector <int> (10000);
        for (int num: arr) {
            hist[num]++;
        }
    }

    // O(n) to add elements
    void track(int x) {
        hist[x]++;
    }

    // O(n) to get the rank of the numbers
    int getRankFromNumber(int x){
        int rank = 0;
        for (int i = 0; i <= x; i++) {
            rank += hist[i];
        }
        return rank - 1;
    }
};

struct RankNode {
    int left_size;
    int val;
    RankNode* left;
    RankNode* right;
    RankNode () : left_size(0), val(0), left(nullptr), right(nullptr) {}
    RankNode (int val) : left_size(0), val(val), left(nullptr), right(nullptr) {}
};

struct Tree {
    RankNode* root;
    Tree() : root(nullptr) {};
    Tree(RankNode* root) : root(root) {}

    void print(RankNode* x) {
        if (x == nullptr) {
            return;
        }
        cout << x->val << endl;
        print(x->left);
        print(x->right);
    }
    RankNode* insert(int x, RankNode* y) {
        if (y == nullptr) {
            return new RankNode(x);
        }
        if (x > y->val) {
            y->right = insert(x, y->right);
        } else if (x <= y->val) {
            y->left_size++;
            y->left = insert(x, y->left);
        }
        return y;
    }

    int getRankForNumber(int x, RankNode* y) {
        if (x > y->val) {
            return y->left_size + 1 + getRankForNumber(x, y->right); // We have to account for the ones that are to the left that are counted when first inserting + the one node compared
        } else if (x < y->val) {
            return getRankForNumber(x, y->left);
        }
        return y->left_size;
    }

};

int main(){
    vector <int> arr = {5,1,4,4,5,9,7,13,3};
    RankedVector* x = new RankedVector(arr);
    for (const auto& num : arr) {
        cout << "arr[" << num <<"]: " << x->getRankFromNumber(num) << endl;
    }

    RankNode* root = new RankNode(5);
    Tree* tree = new Tree(root);
    tree->insert(1, root);
    tree->insert(4, root);
    tree->insert(4, root);
    tree->insert(5, root);
    tree->insert(9, root);
    tree->insert(7, root);
    tree->insert(13, root);
    tree->insert(3, root);
    tree->print(root);

    for (const auto& num: arr) {
        cout << "arr[" << num <<"]: " << tree->getRankForNumber(num, root) << endl;
    }
    return 0;
}