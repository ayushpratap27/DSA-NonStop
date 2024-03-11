#include<bits/stdc++.h>
using namespace std;

int longestContinuousSubstring(string s) {
    int res=1;
    int curr=1;
    for(int i=1;i<s.length();i++){
        if(s[i]==(s[i-1]+1)){
            curr++;
        }
        else{
            res=max(res,curr);
            curr=1;
        }
    }
    res=max(res,curr);
    return res;
}