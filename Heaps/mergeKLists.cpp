#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
class Node {
public:
    int data;
    Node* next;
    
    Node() : data(0), next(nullptr) {}
    
    Node(int data) : data(data), next(nullptr) {}
    
    Node(int data, Node* next) : data(data), next(next) {}
};

struct CompareNodes {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& listArray) {
    // Create a min-heap
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;

    // Push the heads of all linked lists onto the min-heap
    for (Node* listHead : listArray) {
        if (listHead) {
            minHeap.push(listHead);
        }
    }

    // Dummy node to simplify the code
    Node* dummy = new Node();
    Node* current = dummy;

    // Continue until the min-heap is not empty
    while (!minHeap.empty()) {
        // Pop the smallest element from the min-heap
        Node* smallest = minHeap.top();
        minHeap.pop();

        // Append the smallest element to the result list
        current->next = smallest;
        current = current->next;

        // Move to the next node in the linked list of the popped element
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    // Save the head of the merged list
    Node* mergedListHead = dummy->next;

    // Clean up the dummy node
    delete dummy;

    return mergedListHead;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    vector<Node*> listArray;

    // Creating linked lists
    Node* list1 = new Node(4, new Node(6, new Node(8)));
    Node* list2 = new Node(2, new Node(5, new Node(7)));
    Node* list3 = new Node(1, new Node(9));

    listArray.push_back(list1);
    listArray.push_back(list2);
    listArray.push_back(list3);

    // Merging and printing the result
    Node* mergedList = mergeKLists(listArray);
    cout << "Merged List: ";
    printList(mergedList);

    // Clean up allocated memory
    for (Node* listHead : listArray) {
        delete listHead;
    }

    return 0;
}
