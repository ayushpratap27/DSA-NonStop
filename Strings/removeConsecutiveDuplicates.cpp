#include<bits/stdc++.h>
using namespace std;

string removeDuplicate(string &s){
    
    for(int i=0;i<s.length()-1; ){
        if(s[i]==s[i+1]){
            s.erase(i,1);
        }else{
            i++;
        }
    }

    return s;
}