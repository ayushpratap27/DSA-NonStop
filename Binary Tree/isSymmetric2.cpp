#include<bits/stdc++.h>
using namespace std;


template <typename T>
class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        BinaryTreeNode() {
        if(left) 
        delete left;
        if(right) 
        delete right;
    }
};

bool isMirror(BinaryTreeNode<int>* leftSubtree,BinaryTreeNode<int>* rightSubtree){
    
    if(leftSubtree==nullptr && rightSubtree==nullptr)
        return true;
    if(leftSubtree==nullptr || rightSubtree==nullptr)
        return false;

    return (leftSubtree->data==rightSubtree->data) && isMirror(leftSubtree->left,rightSubtree->right) &&
        isMirror(leftSubtree->right,rightSubtree->left);
}

bool isSymmetric(BinaryTreeNode<int>* root) {
    if(root==nullptr)
        return true;

    return isMirror(root->left, root->right);
}