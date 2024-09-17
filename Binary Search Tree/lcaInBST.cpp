#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    int value = root->val;
    if(value < p->val && value < q->val){
        return lowestCommonAncestor(root->right, p, q);
    }
    if(value > p->val && value > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }

    return root;
}