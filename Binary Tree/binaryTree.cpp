#include<bits/stdc++.h>
using namespace std;

//Following is the class structure of the Node class   
class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


Node* createTree(vector<int>& arr){
    if(arr.empty()){
        return NULL;
    }

    Node* root=new Node(arr[0]);
    queue<Node*>q;
    q.push(root);

    for(int i=1;i<arr.size();i+=2){
        Node* current=q.front();
        q.pop();

        if(i<arr.size() && arr[i]!=-1){
            current->left = new Node(arr[i]);
            q.push(current->left);
        }

        if(i<arr.size()-1 && arr[i+1]!=-1){
            current->right=new Node(arr[i+1]);
            q.push(current->right);
        }
    }

    return root;
}