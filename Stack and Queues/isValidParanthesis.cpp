#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i]; // current char
      if (ch == '[' || ch == '{'|| ch=='('){
          st.push(ch);
      }else{
          if(ch==')'&&!st.empty()&&st.top()=='('){
              st.pop();
          } else if (ch == ']' && !st.empty() && st.top() == '[') {
              st.pop();
          }
          else if (ch == '}' && !st.empty() && st.top() == '{') {
              st.pop();
          }else{
              return false;
          }
      }
    }
    return st.empty();
}