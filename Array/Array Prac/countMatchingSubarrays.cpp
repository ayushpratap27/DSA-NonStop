#include<bits/stdc++.h>
using namespace std;

int countMatchingSubarrays(vector<int>& nums,vector<int>& pattern) {
    int n = nums.size();
    int m = pattern.size();
    int cnt = 0;

    for (int i=0;i<n-m;i++) {
        bool match = true;
        for (int j=0;j<m;j++){
            if(pattern[j]==1 && (i+j+1<n) && nums[i+j+1]<=nums[i+j]){
                match=false;
                break;
            }
            if(pattern[j]==0 && nums[i+j+1] != nums[i+j]){
                match=false;
                break;
            }
            if(pattern[j]==-1 && (i+j+1<n) && nums[i+j+1]>=nums[i+j]){
                match = false;
                break;
            }
        }

        if(match){
            cnt++;
        }
    }

    return cnt;
}