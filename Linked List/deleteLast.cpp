#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
 class Node {
 public:
     int data;
     Node *next;
     Node() : data(0), next(nullptr) {}
     Node(int x) : data(x), next(nullptr) {}
     Node(int x, Node *next) : data(x), next(next) {}
 };


Node* deleteLast(Node* list) {
    if (list == nullptr || list->next == nullptr) {
        // Empty list or list has only one node
        delete list;
        return nullptr; // Updated head is null
    }

    Node* current = list;
    Node* previous = nullptr;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    delete current;
    if (previous != nullptr) {
        previous->next = nullptr;
        return list; // Head remains the same
    } else {
        return nullptr; // All nodes are deleted, return null head
    }
}
