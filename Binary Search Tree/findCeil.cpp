#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int findCeil(BinaryTreeNode *node, int x)
{
    int ceil = -1;
    while (node)
    {
        if (node->data == x)
        {
            ceil = node->data;
            return ceil;
        }

        if (x > node->data)
        {
            node = node->right;
        }
        else
        {
            ceil = node->data;
            node = node->left;
        }
    }

    return ceil;
}