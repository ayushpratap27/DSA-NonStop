#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};


int maxPathDown(TreeNode<int>* root, int& maxSum) {
    if(root == NULL) return 0;

    int leftSum = max(0, maxPathDown(root->left, maxSum));
    int rightSum = max(0, maxPathDown(root->right, maxSum));

    maxSum = max(maxSum, root->val + leftSum + rightSum);

    return root->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode<int>* root) {
    int maxSum = INT_MIN; 
    maxPathDown(root, maxSum);
    return maxSum;
}