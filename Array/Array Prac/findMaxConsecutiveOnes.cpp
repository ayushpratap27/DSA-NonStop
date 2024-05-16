#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n=nums.size();
    int maxOnes=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            count++;
        }else{
            count=0;
        }
        maxOnes=max(maxOnes,count);
    }

    return maxOnes;
}