#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode *root, int x)
{
    int floor = -1;
    while (root)
    {
        if (root->val == x)
        {
            floor = root->val;
            return floor;
        }

        if (x > root->val)
        {
            floor = root->val;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return floor;
}