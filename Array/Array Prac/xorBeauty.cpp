#include<bits/stdc++.h>
using namespace std;

int xorBeauty(vector<int>& nums) {
    int x = 0;
    for(auto ele:nums){
        x = x^ele;
    }

    return x;
    
}