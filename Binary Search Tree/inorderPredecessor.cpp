#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//              Recursive 
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    if (root == NULL) return NULL;
    
    if (root->val >= p->val) {
        return inorderPredecessor(root->left, p);
    }
    
    TreeNode* right = inorderPredecessor(root->right, p);
    return right == NULL ? root : right;
}
//   T.C. = O(H)


//             Iterative
TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
    if (root == NULL) return NULL;
    
    if (p->left != NULL) {
        return findMax(p->left);
    }
    
    TreeNode* pred = NULL;
    for (TreeNode* curr = root; curr != NULL; ) {
        if (curr->val > p->val) {
            curr = curr->left;
        } else if (curr->val < p->val) {
            pred = curr;
            curr = curr->right;
        } else {
            break;
        }
    }
    return pred;
}
//    T.C. = O(H)

TreeNode* findMax(TreeNode* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}