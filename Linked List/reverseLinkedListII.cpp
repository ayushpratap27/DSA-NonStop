#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
};

Node* reverseLLRecursion(Node* &head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    //recursion case
    Node* new_head=reverseLLRecursion(head->next);
    head->next->next=head;
    head->next=NULL;//head is now pointing to last node in reversed LL

    return new_head;
}