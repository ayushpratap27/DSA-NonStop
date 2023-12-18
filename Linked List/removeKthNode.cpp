#include<bits/stdc++.h>
using namespace std;


//Following is the class structure of the Node class:

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

Node* removeKthNode(Node* head, int n) {
        // Create a dummy node to simplify edge cases
        Node* dummy = new Node(0);
        dummy->next = head;

        // Initialize two pointers, fast and slow
        Node* fast = dummy;
        Node* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        // Save the new head and delete the dummy node
        Node* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
