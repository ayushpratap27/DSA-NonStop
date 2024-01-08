#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

private:
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        // Process the current node
        result.push_back(node->val);

        // Recursively traverse the left and right subtrees
        preorderHelper(node->left, result);
        preorderHelper(node->right, result);
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    Solution solution;
    vector<int> result = solution.preorderTraversal(root);

    // Display the result
    cout << "Preorder Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
