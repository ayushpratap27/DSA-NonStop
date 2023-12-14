#include<bits/stdc++.h>
using namespace std;


//Definition of linked list
 class Node {

 public:
     int data;
     Node* next;
     Node() : data(0), next(nullptr) {}
     Node(int x) : data(x), next(nullptr) {}
     Node(int x, Node* next) : data(x), next(next) {}
};
 

Node* insertAtFirst(Node* list, int newValue) {
    // Create a new node with the given value
    Node* newNode = new Node(newValue);

    // Set the next of the new node to the current head of the list
    newNode->next = list;

    // Update the head of the list to be the new node
    return newNode;
}