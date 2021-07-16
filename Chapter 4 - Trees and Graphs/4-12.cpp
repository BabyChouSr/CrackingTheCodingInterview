// Paths with Sum
// Reminds me of two sum

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    int val;
    int bf;
    Node* left;
    Node* right;
    Node* parent;
    Node () : val(0), bf(0), left(nullptr), right(nullptr) {}
    Node (int val) : val(val), bf(0), left(nullptr), right(nullptr) {}
};

Node* minimalTree(vector <int> arr, int low, int high) {
    if (arr.size() == 0) {return nullptr;}
    if (low > high) {return nullptr;}

    int mid = (low + high) / 2;
    Node* node = new Node(arr[mid]);
    Node* temp  = minimalTree(arr, low, mid - 1);
    if (temp != nullptr) {
        node->left = temp;
        temp->parent = node;
    }

    Node* temp2 = minimalTree(arr, mid + 1, high);
    if (temp2 != nullptr) {
        node->right = temp2;
        temp2->parent = node;
    }

    return node;
} 

// Returns the number of paths from a certain node
int countPathsWithSumHelper(Node* node, int targetSum, int currentSum) {
    if (node == nullptr) {return 0;}

    currentSum += node->val;

    int totalPaths = 0;
    if (currentSum == targetSum) {
        totalPaths++;
    }

    totalPaths += countPathsWithSumHelper(node->left, targetSum, currentSum);
    totalPaths += countPathsWithSumHelper(node->right, targetSum, currentSum);

    return totalPaths;
}


int countPathsWithSum(Node* node, int targetSum) {
    if (node == nullptr) {return 0;}

    int pathsOnRoot = countPathsWithSumHelper(node, targetSum, 0); // count Paths with sum starting from the root
    int pathsOnLeft = countPathsWithSum(node->left, targetSum); // Tries each node from the left
    int pathsOnRight = countPathsWithSum(node->right, targetSum); // Tries each node from the right

    return pathsOnRoot + pathsOnLeft + pathsOnRight;
}

int countPathsWithSumHelper2(Node* node, int targetSum, int runningSum, map<int, int>& pathCount) {
    if (node == nullptr) {return 0;}

    runningSum += node->val;
    int sum = targetSum - runningSum;
    
    auto found = pathCount.find(sum);
    int totalPaths;
    if (found != pathCount.end()) {
        totalPaths = pathCount[sum];
    }
    else {
        totalPaths = 0;
    }

    if (runningSum == targetSum) {
        totalPaths++;
    }

    pathCount[runningSum]++;

    totalPaths +=  countPathsWithSumHelper2(node->left, targetSum, runningSum, pathCount);
    totalPaths += countPathsWithSumHelper2(node->right, targetSum, runningSum, pathCount);
    
    
    if ((pathCount[runningSum] -= 1) == 0) {
        pathCount.erase(runningSum);
    }

    return totalPaths;
}

// Time Complexity: O(N) because we explore each node once doing O(1) work
// Space Complexity: O(log(N)) for balanced trees or O(N) for unbalanced trees
int countPathsWithSum2(Node* node, int targetSum) {
    map<int, int> tmp;
    return countPathsWithSumHelper2(node, targetSum, 0, tmp);
}

int main (){
    vector <int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    Node* root = minimalTree(arr, 0, arr.size() - 1);

    for (int i = 1; i <= 50; i++) {
        cout << "Sum " << i << " can be reached in "  << countPathsWithSum2(root, i) << endl;
    }
    return 0;
}