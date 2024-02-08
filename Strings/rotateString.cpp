#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    int n = s.length();
    int i = 0;
    while(i<n){
        if(s == goal){
            return true;
        }
        char temp = s[0];
        s.erase(0,1);
        s.push_back(temp);
        i++;
    }
    return false;
}