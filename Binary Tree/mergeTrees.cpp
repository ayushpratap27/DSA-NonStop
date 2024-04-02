#include <bits/stdc++.h> 
using namespace std;


class BinaryTreeNode
{
public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    if (left){
    delete left;
    }
    if (right){
    delete right;
    }

}
};


BinaryTreeNode* mergeTrees(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;

    root1->data += root2->data;

    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}

void preorder(BinaryTreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}