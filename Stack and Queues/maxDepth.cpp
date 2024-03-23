#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int maxCnt=0;
    int open =0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            open++;
        }
        else if (s[i]==')'){
            maxCnt = max(maxCnt , open);
            open--;              
        }
    }

    return maxCnt;
    
}