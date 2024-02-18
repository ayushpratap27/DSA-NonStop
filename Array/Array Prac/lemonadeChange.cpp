#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& s) {
    int s5 = 0;
    int s10 = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]==5){
            s5 += 1;
        }
        if(s[i]==10){
            if(s5!=0){
                s10 += 1;
                s5 -= 1;
            }
            else{
                return false;
            }
        }
        if(s[i]==20){
            if(s5!=0 && s10!=0){
                s5-= 1;
                s10-=1;
            }
            else if(s5>=3){
                s5 -= 3;
            }
            else{
                return false;
            }
        }
    }
    return true;
    }