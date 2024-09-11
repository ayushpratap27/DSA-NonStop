#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void recursion(TreeNode* root, int level, vector<int>& ans){
    if(root == NULL) return;
    if(ans.size() == level) ans.push_back(root->val);
    recursion(root->right, level+1, ans);
    recursion(root->left, level+1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    recursion(root, 0, ans);

    return ans;
}

/*
The time complexity of the given code is O(n) where n is the number of nodes in the binary tree. 
This is because we are visiting each node exactly once in a depth-first manner.

The space complexity of the given code is O(h) where h is the height of the binary tree. 
This is because the recursive function calls will be stored in the call stack up to the height of the tree.
*/