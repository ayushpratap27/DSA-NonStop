#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// void inOrder(TreeNode* root,vector<int>& result) {
//     if(root){
//         inOrder(root->left, result);
//         result.push_back(root->data);
//         inOrder(root->right, result);
//     }
// }

// void preOrder(TreeNode* root, vector<int>& result) {
//     if(root){
//         result.push_back(root->data);
//         preOrder(root->left, result);
//         preOrder(root->right, result);
//     }
// }

// void postOrder(TreeNode* root, vector<int>& result){
//     if(root){
//         postOrder(root->left, result);
//         postOrder(root->right, result);
//         result.push_back(root->data);
//     }
// }

// vector<vector<int>> getTreeTraversal(TreeNode* root){
//     vector<int> inOrderResult;
//     vector<int> preOrderResult;
//     vector<int> postOrderResult;

//     inOrder(root, inOrderResult);
//     preOrder(root, preOrderResult);
//     postOrder(root, postOrderResult);

//     return {inOrderResult, preOrderResult, postOrderResult};
// }

vector<vector<int>> preInPostTraversal(TreeNode* root){
    stack<pair<TreeNode*, int>> st;
    st.push({root,1});
    vector<int> pre, in, post;

    if(root == NULL) return {pre, in ,post};

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        // this is part of pre 
        // increment 1 to 2
        // push the left side of the tree
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }

        // this is part of in
        // increment 2 to 3
        // push the right side of the tree
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }
        // this is part of post
        // increment 3 to 4
        // pop the node from the stack
        
        else{
            post.push_back(it.first->data);
        }

        return {pre, in, post};
    }
}