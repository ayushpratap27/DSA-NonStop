#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k){
    int n = s.size();
    int l = 0, r = 0, maxlen = 0, maxFreq = 0;

    vector<int> v(26, 0);
    while (r < n){
        v[s[r] - 'A']++;
        maxFreq = max(maxFreq, v[s[r] - 'A']);
        if ((r - l + 1) - maxFreq > k){
            v[s[l] - 'A']--;
            l++;
        }

        if ((r - l + 1) - maxFreq <= k){
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }
    return maxlen;
}