#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
      
    for(int i = num.size()-1;i>=0;i--){
        int temp = num[i];
        if(temp%2==1){
            return num.substr(0,i+1);
        }
    }
    return "";
}