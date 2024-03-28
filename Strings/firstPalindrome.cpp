#include<bits/stdc++.h>
using namespace std;

string firstPalindrome(vector<string>& words) {
    for (const string& str : words) {
        int left = 0;
        int right = str.length() - 1;
        bool flag=true;
        while (left < right) {
            if (str[left] != str[right]) {
               flag=false;
            }
            left++;
            right--;
        }
        if(flag) return str;
    }
    return "";
}

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();