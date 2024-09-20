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

class BSTIterator{
    stack<TreeNode*> myStack;
    bool reverse = true;
    public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !myStack.empty();
    }
    int next(){
        TreeNode* top = myStack.top();
        myStack.pop();
        if(!reverse){
            pushAll(top->right);
        }
        else{
            pushAll(top->left);
        }
        return top->val;
    }
    private:
    void pushAll(TreeNode* node){
        while(node){
            myStack.push(node);
            if(reverse){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }
    }

};

class Solution{
    public:
    bool findTarget(TreeNode* root, int k){
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};