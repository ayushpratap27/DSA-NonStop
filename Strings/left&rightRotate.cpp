#include<bits/stdc++.h>
using namespace std;


string leftRotate(string str, int d) {
    int n = str.length();
    d = d % n;  
    reverse(str.begin(), str.begin() + d);
    reverse(str.begin() + d, str.end());
    reverse(str.begin(), str.end());
    return str;
}

string rightRotate(string str, int d) {
    int n = str.length();
    d = d % n;  
    reverse(str.begin(), str.end());
    reverse(str.begin(), str.begin() + d);
    reverse(str.begin() + d, str.end());
    return str;
}