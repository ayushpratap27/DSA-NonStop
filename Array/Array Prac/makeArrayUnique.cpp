#include<bits/stdc++.h>
using namespace std;


int makeArrayUnique(vector<int> &nums, int n){
    sort(nums.begin(),nums.end());
    int cnt = 0;

    for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]){
            nums[i]=nums[i]+1;
            cnt++;
        }
        else if(nums[i]<nums[i-1]){
            cnt += abs(nums[i]-nums[i-1])+1;
            nums[i] = nums[i]+(abs(nums[i]-nums[i-1])+1);
        }
    }
    
    return cnt;
}