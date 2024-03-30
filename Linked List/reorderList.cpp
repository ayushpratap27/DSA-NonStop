#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* nextNode = nullptr;

    while (curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

ListNode* reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow->next;
    slow->next = nullptr;

    secondHalf = reverseList(secondHalf);

    ListNode* firstHalf = head;
    ListNode* temp;

    while (secondHalf != nullptr) {
        temp = firstHalf->next;
        firstHalf->next = secondHalf;
        secondHalf = secondHalf->next;
        firstHalf->next->next = temp;
        firstHalf = temp;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

void deleteList(ListNode* head) {
    ListNode* current = head;
    ListNode* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}