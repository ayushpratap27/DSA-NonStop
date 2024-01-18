#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inOrder(TreeNode* root,vector<int>& result) {
    if(root){
        inOrder(root->left, result);
        result.push_back(root->data);
        inOrder(root->right, result);
    }
}

void preOrder(TreeNode* root, vector<int>& result) {
    if(root){
        result.push_back(root->data);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
}

void postOrder(TreeNode* root, vector<int>& result){
    if(root){
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->data);
    }
}

vector<vector<int>> getTreeTraversal(TreeNode* root){
    vector<int> inOrderResult;
    vector<int> preOrderResult;
    vector<int> postOrderResult;

    inOrder(root, inOrderResult);
    preOrder(root, preOrderResult);
    postOrder(root, postOrderResult);

    return {inOrderResult, preOrderResult, postOrderResult};
}