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

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = findHeightLeft(root);
    int rightHeight = findHeightRight(root);

    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findHeightLeft(TreeNode *node)
{
    int hgt = 0;
    while (node)
    {
        hgt++;
        node = node->left;
    }
    return hgt;
}

int findHeightRight(TreeNode *node)
{
    int hgt = 0;
    while (node)
    {
        hgt++;
        node = node->right;
    }
    return hgt;
}

// int countNodes(TreeNode* root) {
//     if (root == NULL) return 0;

//     int rightLeaves = countNodes(root->right);
//     int leftLeaves = countNodes(root->left);

//     return 1 + leftLeaves + rightLeaves;
// }