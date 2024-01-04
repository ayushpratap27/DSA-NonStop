#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

Node* merge(Node* left, Node* right) {
    Node dummy;
    Node* current = &dummy;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left != nullptr) {
        current->next = left;
    }

    if (right != nullptr) {
        current->next = right;
    }

    return dummy.next;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Split the list into two halves
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* right = slow->next;
    slow->next = nullptr; // Split the list

    // Recursively sort both halves
    Node* leftSorted = mergeSort(head);
    Node* rightSorted = mergeSort(right);

    // Merge the sorted halves
    return merge(leftSorted, rightSorted);
}

Node* sortList(Node* head) {
    return mergeSort(head);
}

// Example usage
int main() {
    Node* head = new Node(3, new Node(1, new Node(2)));
    Node* sortedList = sortList(head);

    // Print the sorted list
    Node* current = sortedList;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
