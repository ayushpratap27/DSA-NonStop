#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* successor = NULL;
    while(root){
        if(root->val > p->val){ 
            successor = root;
            root = root->left;
        }
        else root = root->right;
    }
    return successor;
}