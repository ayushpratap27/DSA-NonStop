#include<bits/stdc++.h>
using namespace std;

//************ Brute Force******************

vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
        
    vector<int> result(2);
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(nums[i]+nums[j]==target && i!=j){
                result[0]=i;
                result[1]=j;
            }
        }
    }

    return result;

}