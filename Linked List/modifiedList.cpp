#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> freq(nums.begin(), nums.end());
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while(head != nullptr){
        if(freq.find(head->val) == freq.end()){
            current->next = head;
            current = current->next;
        }
        head = head->next;
    }

    current->next = nullptr;
    return dummy->next;
}

/*
The time complexity of this function is O(n), where n is the number of nodes in the linked list. 
This is because we iterate through each node in the linked list once.

The space complexity is O(m), where m is the number of unique elements in the input vector nums. 
This is because we store the unique elements in a set, which can have a maximum of m elements. 
Additionally, we create a new ListNode for each element in the linked list that is not in the set, 
which also contributes to the space complexity.
*/