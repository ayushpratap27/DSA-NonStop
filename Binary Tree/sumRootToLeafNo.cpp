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

int sumNumbers(TreeNode* root,string num = "") {
    if(root==NULL){
        return 0;
    }

    num+= to_string(root->val);

    if(!root->left && !root->right){
        return stoi(num);
    }
        
    int result1 = sumNumbers(root->left,num);
    int result2 = sumNumbers(root->right,num);

    return result1+result2;
}

