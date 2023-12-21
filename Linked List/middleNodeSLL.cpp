#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:

    int size(ListNode* head){
        ListNode* tmp = head;
        int s = 0;
        while(tmp != NULL){
            s++;
            tmp = tmp->next;
        }
        return s;
    }
    ListNode* middleNode(ListNode* head) {
        int s = size(head);
        ListNode* tmp = head;
        for(int i = 0;i<s/2;i++){
            tmp = tmp->next;
        }
        return tmp;

    }
};