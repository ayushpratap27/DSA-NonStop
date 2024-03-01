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


int maxPathSumUtil(TreeNode<int>* root, int& maxSum) {
    if(root == NULL){
        return 0;
    }

    int leftSum = max(0, maxPathSumUtil(root->left, maxSum));
    int rightSum = max(0, maxPathSumUtil(root->right, maxSum));

    maxSum = max(maxSum, root->val + leftSum + rightSum);

    return root->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode<int>* root) {
    int maxSum = INT_MIN; 
    maxPathSumUtil(root, maxSum);
    return maxSum;
}