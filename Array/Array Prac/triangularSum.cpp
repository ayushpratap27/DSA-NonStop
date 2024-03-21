#include<bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    int i;
    int k = 1;
    while(nums.size()-k!=0){
        for(i = 0; i < nums.size()-k; i++){
            nums[i] = (((nums[i]+nums[i+1])%10));
        }
        k++;
    }

    return nums[0];
    
}