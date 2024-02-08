#include<bits/stdc++.h>
using namespace std;

int minimizedStringLength(string s) {

    sort(s.begin(),s.end());

    if(s.length()==1){
        return 1;
    }
    
    int i=1;
    while(i<s.size()){
        if(s[i]==s[i+1]){
            s.erase(i+1,1);
        }
        if(s[i]==s[i-1]){
            s.erase(i-1,1);
        }else{
            i++;
        }
    }
        
    return s.length();
}