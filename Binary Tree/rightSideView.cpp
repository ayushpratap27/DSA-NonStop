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

vector<int> ans;
void solve(TreeNode* root,int l){
    if(root==NULL){
        return;
    }
    if(ans.size()==l) ans.push_back(root->val);
    solve(root->right,l+1);
    solve(root->left,l+1);
}
vector<int> rightSideView(TreeNode* root) {
    solve(root,0);
    return ans;
}

/*
The time complexity of the given code is O(n) where n is the number of nodes in the binary tree. 
This is because we are visiting each node exactly once in a depth-first manner.

The space complexity of the given code is O(h) where h is the height of the binary tree. 
This is because the recursive function calls will be stored in the call stack up to the height of the tree.
*/