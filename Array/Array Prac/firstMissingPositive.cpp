#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    set<int>st;
    int i=1;
    for(auto ele:nums){
        if(ele>0){
            st.emplace(ele);
        }
    }
    for(auto ele:st){
        if(ele!=i){
            return i;
        }
        else{
            i++;
        }
    }

    return st.size()+1;
}