#include<bits/stdc++.h>
using namespace std;

string customSortString(string order, string s) {
    string ans="";
    for(int i=0;i<order.size();i++){
        if(s.find(order[i])!=string::npos){
           int n= count(s.begin(),s.end(),order[i]);
           while(n){
               ans+=order[i];
               n--;
                   
           }
                
        }
    }

    string temp="";
    for(auto  ele:s){
        if(order.find(ele)==string::npos){
            temp+=ele;
        }
    }

    ans+=temp;
    return ans;
        
}