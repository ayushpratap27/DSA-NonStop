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


int calculateDiameter(TreeNode* root, int& diameter) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = calculateDiameter(root->left, diameter);
    int rightDepth = calculateDiameter(root->right, diameter);
    diameter=max(diameter,leftDepth+rightDepth);

    return 1 + max(leftDepth, rightDepth);
}

int diameterOfBinaryTree(TreeNode* root){
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}
