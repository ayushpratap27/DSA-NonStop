#include<bits/stdc++.h>
using namespace std;

string maximumOddBinaryNumber(string s) {
    int zeros=0,ones = 0;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zeros++;
        }
        else{
            ones++;
        }
    }
    string ans;
    while(ones>1){
        ans.push_back('1');
        ones--;
    }
    while(zeros>0){
        ans.push_back('0');
        zeros--;
    }
    ans.push_back('1');
    return ans;
}