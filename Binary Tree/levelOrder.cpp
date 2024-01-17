#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> levelOrder(TreeNode<int> *root) {
    vector<int> result;
    if(!root){
      return result;
    }

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* node=q.front();
        q.pop();

        result.push_back(node->data);

        if(node->left){
            q.push(node->left);
        }
        if(node->right){
            q.push(node->right);
        }
    }

    return result;
}