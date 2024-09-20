#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int maxNode, int minNode, int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution
{
private:
    NodeValue largestBSTSubtreeHelper(TreeNode *root)
    {
        if (root == nullptr)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        NodeValue left = largestBSTSubtreeHelper(root->left);
        NodeValue right = largestBSTSubtreeHelper(root->right);

        if (root->val > left.maxNode && root->val < right.minNode)
        {
            return NodeValue(min(root->val, left.minNode),
                             max(root->val, right.maxNode),
                             left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubtree(TreeNode *root)
    {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};