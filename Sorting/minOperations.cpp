#include<bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums) {
    int n = nums.size();
    int cnt=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            int x=nums[i];
            for(int j=i;j<nums.size();j++){
                nums[j]=nums[j]-x;
            }
            cnt++;
        }
    }

    return cnt;
}