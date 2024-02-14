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

vector<int> ans;
void solve(TreeNode* root,int l){
    if(root==NULL){
        return;
    }
    if(ans.size()==l) ans.push_back(root->val);
    solve(root->right,l+1);
    solve(root->left,l+1);
}
vector<int> rightSideView(TreeNode* root) {
    solve(root,0);
    return ans;
}