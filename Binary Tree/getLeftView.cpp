#include <bits/stdc++.h> 
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


vector<int> getLeftView(TreeNode<int> *root) {
    vector<int> leftView;

    if (root == nullptr) {
        return leftView;
    }

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode<int> *current = q.front();
            q.pop();

            if (i == 0) {
                // The first node in each level is part of the left view
                leftView.push_back(current->data);
            }

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }
    }

    return leftView;
}