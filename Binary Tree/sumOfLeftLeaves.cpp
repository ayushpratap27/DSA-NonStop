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

// void solve(TreeNode* root,bool flag,int &sum){
//     if(!root) return;
//     if(!root->left && !root->right){
//         if(flag) 
//             sum += root->val;
//         return;
//     }
//     solve(root->left,true,sum);
//     solve(root->right,false,sum);
// }
// int sumOfLeftLeaves(TreeNode* root) {
//     if(root==NULL) return 0;
//     int sum = 0;
//     solve(root->left,true,sum);
//     solve(root->right,false,sum);
//     return sum;
// }

int sumOfLeftLeaves(TreeNode* root) {

    if (!root){
        return  0;
    }

    int sum=0;

    vector<pair<TreeNode*, bool>> stack={{root, 0}};
    
    while(!stack.empty()){
        auto [Node, isLeft]=stack.back();
        stack.pop_back();
        if (!Node->left && !Node->right && isLeft){
            sum+=Node->val;
        }else{
            if (Node->right)stack.emplace_back(Node->right, 0);
            if (Node->left) stack.emplace_back(Node->left, 1);
        }
    }

    return sum;

}