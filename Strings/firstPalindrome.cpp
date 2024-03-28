#include<bits/stdc++.h>
using namespace std;


bool isPalindrome (const string &s) {
    int left = 0, right = s.length() - 1;

    while (left<=right) {
        if (s[left++] != s[right--])
            return false;
    } 
        
    return true; 
}
string firstPalindrome(vector<string>& words) {
    for (string s : words)
        if(isPalindrome(s))
            return s;
                
    return "" ;
}