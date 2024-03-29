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

bool solve(TreeNode* root,int data){
        if(root==NULL){
            return true;
        }
        if(root->val!=data){
            return false;
        }
        return solve(root->left,data) && solve(root->right,data);
    }
bool isUnivalTree(TreeNode* root) {
    return solve(root,root->val);
}