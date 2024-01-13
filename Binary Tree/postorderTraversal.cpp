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

vector<int> postorderTraversal(TreeNode *root){
    vector<int>result;
    postorderTraversalHelper(root, result);
    return result;
}
void postorderTraversalHelper(TreeNode *root, vector<int> &result){
    if(root==nullptr) 
    return;

    postorderTraversalHelper(root->left, result);
    postorderTraversalHelper(root->right, result);

    result.push_back(root->val);
}