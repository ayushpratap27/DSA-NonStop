#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else if(s[i]==st.top()){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    string result="";
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;
}