#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(i<j){
                    if(nums[i]+nums[j] < target)
                    count++;
                }
            }
        }

        return count;

}