// List of Depths

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

TreeNode* minimalTree(vector <int> arr, int low, int high) {
    if (arr.size() == 0) {return nullptr;}
    if (low > high) {return nullptr;}

    int mid = (low + high) / 2;
    TreeNode* node = new TreeNode(arr[mid]);
    node->left = minimalTree(arr, low, mid - 1);
    node->right = minimalTree(arr, mid + 1, high);
    return node;
} 

int height (TreeNode* n) {
    if (n == nullptr) {return 0;}
    return 1 + max(height(n->left), height(n->right)); 
}

void printLinkedLists (vector<ListNode*> vec) {
    for (const auto& node: vec) {
        ListNode* curr = node;
        while (curr != nullptr) {
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << endl;
    }
}

void printTreeNodes (vector<list<TreeNode*>> vec) {
    queue <TreeNode*> q;
    for (const auto& listnode: vec) {
        for (const auto& node: listnode) {
            cout << node->val << "->";
        }
        cout << endl;
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<ListNode*> listOfDepths (TreeNode* root) {
    queue <TreeNode*> q;
    map <int, vector<TreeNode*> > m;
    q.push(root);
    vector <ListNode*> linked_lists;
    while (!q.empty()) {
        TreeNode* t = q.front();
        m[height(t)].push_back(t);
        q.pop();
        if (t->left != nullptr) {
            q.push(t->left);
        } 
        if (t->right != nullptr) {
            q.push(t->right);
        }
    }

    bool flag = false;
    for (const auto& pairNode: m) {
        for (const auto& nNode: pairNode.second) {
            if (!flag) {
                linked_lists.push_back(new ListNode(nNode->val));
                flag = true;
            } else {
                ListNode* curr = linked_lists[pairNode.first - 1];
                while (curr->next != nullptr) {
                    curr = curr->next;
                } 
                curr->next = new ListNode(nNode->val);
            }
        }
        flag = false;
    }
    return linked_lists;
}

//Recursive so it has extra O(log N) recursive calls
// Space Complexity: O(n)
// Time Complexity: O(n)
void listOfDepths2(TreeNode* root, vector<ListNode*> & llist, int level) {
    if (root == nullptr) {return;}
    if (level == llist.size()) {
        ListNode* l = new ListNode(root->val);
        llist.push_back(l);
    } else {
        ListNode* curr = llist[level];
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new ListNode(root->val);
    }
    listOfDepths2(root->left, llist, level +1);
    listOfDepths2(root->right, llist, level + 1);
}


// Idea is that if we are traversing downwards then if we are on i'th level then we must have traveled to the (i-1)'th level
// Iteratively searches through the tree, similar to breadth first search
// Basically, we get the first row, then we get the left and right of the first row and etc.
vector<list<TreeNode*>> listOfDepths3(TreeNode* root) {
    vector<list<TreeNode*>> result;
    list<TreeNode*> current;
    if (root != nullptr) {current.push_back(root); }
    while (!current.empty()) {
        result.push_back(current);
        cout << "here" << endl;
        list<TreeNode*> parents = current;
        list<TreeNode*> current;
        for (TreeNode* parent: parents) {
            if (parent->left != nullptr) {
                current.push_back(parent->left);
            }
            if (parent->right != nullptr) {
                current.push_back(parent->right);
            }
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    TreeNode* root = minimalTree(arr, 0, arr.size() - 1);
    vector<ListNode*> llist;
    // listOfDepths2(root, llist, 0);
    // printLinkedLists(llist);
    printTreeNodes(listOfDepths3(root));
}