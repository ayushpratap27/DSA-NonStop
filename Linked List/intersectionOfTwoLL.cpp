#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if(!headA || !headB){
        return nullptr; 
    }

    ListNode* ptrA=headA;
    ListNode* ptrB=headB;

    while(ptrA!=ptrB){
       
        ptrA=(ptrA ? ptrA->next:headB);
        ptrB=(ptrB ? ptrB->next:headA);
    }

    return ptrA; 
}