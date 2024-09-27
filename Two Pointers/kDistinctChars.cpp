#include<bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str)
{   
    int n = str.size();
    int l = 0, r = 0, maxlen = 0;
    map<char, int> mp;
    int cnt = 0;

    while(r < n){
        mp[str[r]]++;
        if(mp[str[r]] == 1) cnt++;
        if(cnt > k){
            mp[str[l]]--;
            if(mp[str[l]] == 0) cnt--;
            l++;
        }
        if(cnt <= k){
            maxlen = max(maxlen, r - l + 1);
        }

        r++;
    }

    return maxlen;
}