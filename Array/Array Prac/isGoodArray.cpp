#include<bits/stdc++.h>
using namespace std;

bool isGoodArray(vector<int>& nums) {
        int x = nums[0];
        for(int i=0;i<nums.size();i++){
            x = __gcd(x,nums[i]);
            if(x==1){
                return true;
            }
        }
        return false;
}