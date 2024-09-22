#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

void inorder(TreeNode *root, vector<int> &v){
    if (root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}


vector<int> getAllElements(TreeNode *root1, TreeNode *root2){
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);

    int n = v1.size(), m = v2.size();
    vector<int> ans(n + m);
    int i = 0, j = 0, k = 0;

    while (i < n && j < m){
        if (v1[i] < v2[j])
        {
            ans[k++] = v1[i++];
        }
        else
        {
            ans[k++] = v2[j++];
        }
    }

    while (i < n)
        ans[k++] = v1[i++];
    while (j < m)
        ans[k++] = v2[j++];

    return ans;
}