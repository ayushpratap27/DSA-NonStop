#include<bits/stdc++.h>
using namespace std;

int countDistinctIntegers(vector<int>& nums) {
    set<int> st;
    for(auto ele: nums){
        st.insert(ele);
        int r = 0;
        while(ele){
            r = r*10 + ele%10;
            ele = ele/10;
        }
        st.insert(r);
    }

    return st.size();
    
}