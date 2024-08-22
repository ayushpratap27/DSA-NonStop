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

void preOrder(TreeNode *root, vector<int> &result){
    if(root==nullptr) 
    return;

    preOrder(root->left, result);
    preOrder(root->right, result);

    result.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode *root){
    vector<int>result;
    preOrder(root, result);
    return result;
}