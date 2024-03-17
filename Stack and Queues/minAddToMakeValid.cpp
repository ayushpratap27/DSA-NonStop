#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    
    stack<char> st;
    int count = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    count++;
                }
            }
            else{
                count++;
            }
        }
    }

    if(st.empty()){
        return count;
    }

    int ans = count + st.size();
    return ans;

}