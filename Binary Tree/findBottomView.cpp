#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;                               
    Node *left = nullptr, *right = nullptr; 

    Node() {}
    Node(int data) : data(data) {}
    Node(int data, Node *left, Node *right) : data(data), left(left), right(right) {}
};

vector<int> findBottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;           
    queue<pair<Node *, int>> Q; 
    Q.push({root, 0});
    while (!Q.empty())
    {
        auto it = Q.front();
        Q.pop();
        Node *node = it.first;
        int col = it.second;
        mp[col] = node->data;
        if (node->left != NULL)
            Q.push({node->left, col - 1});
        if (node->right != NULL)
            Q.push({node->right, col + 1});
    }
    for (auto x : mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}