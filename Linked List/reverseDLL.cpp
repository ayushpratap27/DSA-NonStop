#include<bits/stdc++.h>
using namespace std;


//Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};


Node *reverseDLL(Node *head)
{
    Node *current = head;
    Node *temp = NULL;

    // Swap 'prev' and 'next' pointers for each node
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Check if the list is not empty
    if (temp != NULL)
    {
        head = temp->prev; // Update the head to the last node
    }

    return head;
}

