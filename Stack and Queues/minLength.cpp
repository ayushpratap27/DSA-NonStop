#include <bits/stdc++.h>
using namespace std;

int minLength(string s){
    int n = s.size();
    stack<char> stck;
    stck.push('#');
    for (int i = 0; i < n; i++){
        stck.push(s[i]);

        if (stck.top() == 'B'){
            stck.pop();
            if (stck.top() == 'A'){
                stck.pop();
            }
            else{
                stck.push('B');
            }
        }
        else if (stck.top() == 'D'){
            stck.pop();
            if (stck.top() == 'C'){
                stck.pop();
            }
            else{
                stck.push('D');
            }
        }
    }
    
    return stck.size() - 1;
}