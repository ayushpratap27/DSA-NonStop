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

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

// template <typename T>
// LinkedListNode<T> *reverseLinkedList(LinkedListNode<T> *head) 
// {
//     LinkedListNode<T> *prev = nullptr;
//     LinkedListNode<T> *current = head;
//     LinkedListNode<T> *next = nullptr;

//     while (current != nullptr) {
//         next = current->next;  // Save the next node
//         current->next = prev;  // Reverse the link

//         // Move to the next nodes
//         prev = current;
//         current = next;
//     }

//     return prev;  // The new head is the last node (previously the tail)
// }
