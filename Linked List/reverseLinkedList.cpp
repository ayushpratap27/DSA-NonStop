#include<bits/stdc++.h>
using namespace std;



   // Following is the class structure of the Node class:

        class Node
        {
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
        
//************************ Iterative Solution ********************

Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node* prevptr=NULL;
    Node* currptr=head;

    //currptr->next=prevptr;
    //move all 3 ptr by one step ahead
    while(currptr!=NULL){
        Node* nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }

    Node* new_head=prevptr;

    return new_head;
}
