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

int traverse(TreeNode *root, int minVal, int maxVal)
{
    int diff = INT_MAX;
    diff = min(abs(root->val - minVal), abs(root->val - maxVal));
    int diff1 = INT_MAX, diff2 = INT_MAX;
    if (root->left != NULL)
        diff1 = traverse(root->left, minVal, root->val);
    if (root->right != NULL)
        diff2 = traverse(root->right, root->val, maxVal);

    return min(diff, min(diff1, diff2));
}

int minDiffInBST(TreeNode *root)
{
    return traverse(root, -100001, 200001);
}
