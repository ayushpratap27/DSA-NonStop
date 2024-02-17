#include<bits/stdc++.h>
using namespace std;

int minimumParentheses(string& pattern) {
    int count = 0; 
    stack<char> st; 

    for(char ch : pattern){
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (!st.empty()) {
                st.pop(); 
            } else {
                count++;
            }
        }
    }

    count += st.size();

    return count;
}