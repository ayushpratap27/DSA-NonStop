#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n == 0) return 0;
        
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     unordered_set<char> set;
    //     int cnt = 0;
    //     for (int j = i; j < n; j++) {
    //         if (set.find(s[j]) == set.end()) {
    //             set.insert(s[j]);
    //             cnt++;
    //         } else {
    //             break;
    //         }
    //     }
    //     ans = max(ans, cnt);
    // }
    // return ans;

    unordered_set<char> st;
    int left = 0, right = 0;
    int ans = 0;
    while(right < n){
        if(st.find(s[right]) == st.end()){
            st.insert(s[right]);
            ans = max(ans, right - left + 1);
            right++;
        }else{
            st.erase(s[left]);
            left++;
        }
    }

    return ans;
}