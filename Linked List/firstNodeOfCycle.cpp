#include<bits/stdc++.h>
using namespace std;



  //  Following is the class structure of the Node class:

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




Node *firstNode(Node *head) {
        if (!head || !head->next) {
            return NULL; // No cycle
        }

        Node *slow = head;
        Node *fast = head;
        Node *entry = head;

        // Detect cycle using Floyd's Tortoise and Hare algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected, find the entry point
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry; // Return the node where the cycle begins
            }
        }

        return NULL; // No cycle
    }