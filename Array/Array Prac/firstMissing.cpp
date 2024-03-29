#include<bits/stdc++.h>
using namespace std;

int firstMissing(int nums[], int n) {
    set<int>st;
    int i=1;
    for(int j=0;j<n;j++){
        if(nums[j]>0){
            st.emplace(nums[j]);
        }
    }
    for(int k=0;k<st.size();k++)
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