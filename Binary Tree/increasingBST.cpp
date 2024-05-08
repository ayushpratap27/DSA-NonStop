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

void Inorder(TreeNode* root,queue<TreeNode*>&q)
{
    if(root==NULL)return;
    Inorder(root->left,q);
    q.push(root);
    Inorder(root->right,q);
}
TreeNode* increasingBST(TreeNode* root) {
    if(root==NULL)return NULL;
    queue<TreeNode*>q;
    Inorder(root,q);
    root=q.front();q.pop();
    TreeNode* temp=root;
    while(q.empty()==false)
    {
        TreeNode* node=q.front();
        q.pop();
        temp->left=NULL;
        temp->right=node;
        temp=node;
        
    }
    temp->left=NULL;
    temp->right=NULL;
    return root;
}
