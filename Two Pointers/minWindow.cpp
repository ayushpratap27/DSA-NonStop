#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t){
    int n = s.size(), m = t.size();
    if (n < m)
        return "";

    unordered_map<char, int> mp;
    for (char c : t)
        mp[c]++;

    int required = m;
    int l = 0, r = 0, minlen = 1e9, startIdx = 0;

    while (r < n){
        if (mp[s[r]] > 0)
            required--;
        mp[s[r]]--;

        while (required == 0){
            if (r - l + 1 < minlen){
                minlen = r - l + 1;
                startIdx = l;
            }

            mp[s[l]]++;
            if (mp[s[l]] > 0)
                required++;
            l++;
        }
        r++;
    }

    return minlen == 1e9 ? "" : s.substr(startIdx, minlen);
}