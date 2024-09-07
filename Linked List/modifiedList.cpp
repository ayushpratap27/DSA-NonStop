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