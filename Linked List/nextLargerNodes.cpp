#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode *head){
    vector<int> nums;
    ListNode *temp = head;
    while (temp != NULL){
        nums.push_back(temp->val);
        temp = temp->next;
    }
    int n = nums.size();
    cout << n;
    vector<int> nge(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (i < n)
        {
            nge[i] = st.empty() ? 0 : st.top();
        }
        st.push(nums[i]);
    }
    return nge;
}