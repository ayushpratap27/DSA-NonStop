#include <bits/stdc++.h>
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

TreeNode *insertIntoBST(TreeNode *root, int val){

    TreeNode *curr = root;
    TreeNode *newNode = new TreeNode(val);
    if (root == NULL)
        return newNode;
    while (true){
        if (curr->val >= val)
        {
            if (curr->left != NULL)
                curr = curr->left;
            else
            {
                curr->left = newNode;
                break;
            }
        }
        else
        {
            if (curr->right != NULL)
                curr = curr->right;
            else
            {
                curr->right = newNode;
                break;
            }
        }
    }
    return root;
}