#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ListNode *insertGreatestCommonDivisors(ListNode *head)
{

    if (!head || !head->next)
    {
        return head;
    }
    ListNode *prev = head;
    ListNode *temp = head->next;

    while (temp)
    {
        ListNode *node = new ListNode(gcd(prev->val, temp->val));
        prev->next = node;
        node->next = temp;
        prev = temp;
        temp = temp->next;
    }

    return head;
}