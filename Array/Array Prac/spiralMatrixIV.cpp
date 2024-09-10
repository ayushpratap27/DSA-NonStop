#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    ListNode* node = head;

    vector<vector<int>> ans(m, vector<int>(n, -1));
        
    while(left <= right && top <= bottom && node){
        for(int i=left; i<=right && node; i++){
            ans[top][i] = node->val;
            node = node->next;
        }
        top++;

        for(int i=top; i<=bottom && node; i++){
            ans[i][right] = node->val;
            node = node->next;
        }
        right--;

        if(top <= bottom){
            for(int i=right; i>=left && node; i--){
                ans[bottom][i] = node->val;
                node = node->next;
            }
            bottom--;
        }

        if(left <= right){
            for(int i=bottom; i>=top && node; i--){
                ans[i][left] = node->val;
                node = node->next;
            }
            left++;
        }
    }

    return ans;
}