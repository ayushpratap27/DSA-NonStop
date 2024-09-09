#include<bits/stdc++.h>
using namespace std;

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*>ans;
    ListNode* temp=head;
    int c=0;
    while(temp){
        c++;
        temp=temp->next;
    }
    int equal=c/k,extra=c%k;
    ListNode* prevHead=head;
    while(k--){
        int t=equal;
        if(extra>0) t++;
        t--;
        ListNode* newHead=prevHead;
        ListNode* temp=newHead;
        while(newHead && t--){
            newHead=newHead->next;
        }
        if(newHead){
            prevHead=newHead->next;
            newHead->next=NULL;
        }
        ans.push_back(temp);
        extra--;
    }
    return ans;
}