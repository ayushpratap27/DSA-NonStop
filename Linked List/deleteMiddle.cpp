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


Node* deleteMiddle(Node* head){
    // Write your code here.
        if (head == nullptr || head->next == nullptr) {
            // No or only one node in the list
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now 'slow' is the middle node
        if (prev != nullptr) {
            // Adjust pointers to skip the middle node
            prev->next = slow->next;
        } else {
            // If the head is the middle node, update the head
            head = head->next;
        }

        delete slow; // Deallocate the memory of the middle node

        return head;
}
