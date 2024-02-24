#include<bits/stdc++.h>
using namespace std;

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


Node* sortList(Node *head) {
    if (!head || !head->next) {
        return head; 
    }

    Node *zeroHead = new Node(0);
    Node *oneHead = new Node(0);
    Node *twoHead = new Node(0);

    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    Node *current = head;

    while (current) {
        if (current->data == 0) {
            zeroTail->next = current;
            zeroTail = zeroTail->next;
        } else if (current->data == 1) {
            oneTail->next = current;
            oneTail = oneTail->next;
        } else {
            twoTail->next = current;
            twoTail = twoTail->next;
        }

        current = current->next;
    }

    zeroTail->next = oneHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}