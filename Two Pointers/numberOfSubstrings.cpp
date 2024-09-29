#include <bits/stdc++.h>
using namespace std;

bool allLetters(unordered_map<char, int> &mp){
    return mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0;
}

int numberOfSubstrings(string s){
    int n = s.size();
    int cnt = 0, l = 0, r = 0;
    unordered_map<char, int> mp;
    while (r < n){
        mp[s[r]]++;
        while (allLetters(mp)){
            cnt += (n - r);
            mp[s[l]]--;
            l++;
        }
        r++;
    }
    return cnt;
}