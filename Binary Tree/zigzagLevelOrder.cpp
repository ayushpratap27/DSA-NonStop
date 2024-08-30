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


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root){
    return result;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> row(size);

        for(int i=0;i<size;i++) {
            TreeNode* node = q.front();
            q.pop();

            int index=(leftToRight) ? i : (size-1-i);
            row[index]= node->val;

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }

        result.push_back(row);
        leftToRight = !leftToRight;
    }

    return result;
}


//The time complexity of this algorithm is O(n), where n is the number of nodes in the binary tree. 
//This is because we are visiting each node once in a level order traversal using a queue.

//The space complexity is also O(n), as in the worst case scenario, the queue can hold all 
//the nodes at the last level of the binary tree, which can be at most n/2 nodes. Additionally, the 
//result vector will also hold all the nodes in the tree.