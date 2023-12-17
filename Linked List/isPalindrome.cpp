#include<bits/stdc++.h>
using namespace std;

 //   Following is the class structure of the Node class:

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


bool isPalindrome(Node *head)
{
    // write your code here
    //1.Find middle element
    Node* slow=head;
    Node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    //Now slow is pointing to middle element
    //2.Break the linked list in the middle

    Node* curr=slow->next;
    Node* prev=slow;
    slow->next=NULL;

    //3.reverse the 2nd half of LL
    while(curr){
        Node* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }

    //4.Check if the two linked lists are equal
    Node* head1=head;
    Node* head2=prev;

    while(head2){
        if(head1->data!=head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }

    return true;
}