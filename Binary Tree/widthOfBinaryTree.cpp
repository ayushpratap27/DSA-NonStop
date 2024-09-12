#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode *root){
    if (root == NULL)
        return 0;
    int width = 0;
    queue<pair<TreeNode *, long long>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        long long min = q.front().second;
        long long first, last;
        for (int i = 0; i < size; i++)
        {
            long long curr_id = q.front().second - min;
            TreeNode *node = q.front().first;
            q.pop();

            if (i == 0)
                first = curr_id;
            if (i == size - 1)
                last = curr_id;

            if (node->left)
                q.push({node->left, curr_id * 2});
            if (node->right)
                q.push({node->right, curr_id * 2 + 1});
        }
        width = max(width, static_cast<int>(last - first + 1));
    }

    return width;
}