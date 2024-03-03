#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};


Node *insert(Node *head, int n, int pos, int val) {
    Node *newNode = new Node(val);

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    Node *current = head;
    for (int i = 0; i < pos - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}
