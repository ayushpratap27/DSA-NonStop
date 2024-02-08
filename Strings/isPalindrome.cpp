#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    string alphanumericStr;
    for(char c : s){
        if((c>='a' && c<='z') || (c>='0' && c<='9')){
            alphanumericStr+=c;
        }
    }

    string revStr = alphanumericStr;
    reverse(revStr.begin(),revStr.end());

    return alphanumericStr==revStr;
}