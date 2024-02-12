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

void solve(TreeNode* root,bool flag,int &sum){
    if(!root) return;
    if(!root->left && !root->right){
        if(flag) 
            sum += root->val;
        return;
    }
    solve(root->left,true,sum);
    solve(root->right,false,sum);
}
int sumOfLeftLeaves(TreeNode* root) {
    if(root==NULL) return 0;
    int sum = 0;
    solve(root->left,true,sum);
    solve(root->right,false,sum);
    return sum;
}