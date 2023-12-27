#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(const string& s) {
    string result = "";
    int openCount = 0;

    for (char c : s) {
        if (c == '(') {
            if (openCount > 0) {
                result += '(';
            }
            openCount++;
        } else {
            openCount--;
            if (openCount > 0) {
                result += ')';
            }
        }
    }

    return result;
}