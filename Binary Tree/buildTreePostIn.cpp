#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size())
    {
        return NULL;
    }

    map<int, int> mp;

    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0,
                           postorder.size() - 1, mp);
}

TreeNode *buildTreePostIn(vector<int> &inorder, int inStart, int inEnd,
                          vector<int> &postorder, int poStart, int poEnd,
                          map<int, int> &mp)
{
    if (inStart > inEnd || poStart > poEnd)
        return NULL;

    TreeNode *root = new TreeNode(postorder[poEnd]);

    int inRoot = mp[postorder[poEnd]];
    int numLeft = inRoot - inStart;

    root->left = buildTreePostIn(inorder, inStart, inRoot - 1, postorder,
                                 poStart, poStart + numLeft - 1, mp);

    root->right = buildTreePostIn(inorder, inRoot + 1, inEnd, postorder,
                                  poStart + numLeft, poEnd - 1, mp);

    return root;
}