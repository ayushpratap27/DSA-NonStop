#include<bits/stdc++.h>
using namespace std;


int differenceOfSum(vector<int>& nums) {
    int n = nums.size();
    int eleSum = 0;
    for(int i=0;i<n;i++){
        eleSum += nums[i];
    }
    int digitSum = 0;
    for(int i=0;i<n;i++){
        int x = nums[i];
        while(x!=0){
            int digit = x%10;
            digitSum += digit;
            x = x/10;
        }
    }
    return abs(eleSum-digitSum);
    
}