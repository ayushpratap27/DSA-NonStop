#include <bits/stdc++.h> 
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void changeTree(TreeNode* root) {
    if(root == NULL) return;
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }

    if(child >= root->data) root->data = child;
    else{
        if(root->left) root->left->data = root->data;
        else if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    if(root->left || root->right) root->data = total;
} 