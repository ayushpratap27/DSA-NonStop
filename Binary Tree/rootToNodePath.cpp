#include<bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

bool getPath(TreeNode<int>* root, int x, vector<int>& path){
	if(root == NULL) 
		return false;

	path.push_back(root->data);

	if(root->data == x) return true;

	if(getPath(root->left, x, path) || getPath(root->right, x, path)){
		return true;
	}

	path.pop_back();
	return false;

}


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> path;

	if(root == NULL) return path;

	getPath(root, x, path);
	return path;
}

//  T.C. = O(N)
//  S.C. = O(H)