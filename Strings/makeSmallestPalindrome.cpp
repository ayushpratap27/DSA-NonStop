#include<bits/stdc++.h>
using namespace std;

string makeSmallestPalindrome(string s) {
    for(int i=0; i<s.size()/2; i++){
        if(s[i]!=s[s.size()-1-i]){
            (s[i]<s[s.size()-1-i]) ? s[s.size()-1-i]=s[i] : s[i]=s[s.size()-1-i];
        }
    }
    return s;
}