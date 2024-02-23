#include<bits/stdc++.h>
using namespace std;

int maximizeSum(vector<int>& nums, int k) {
    int n = nums.size()-1;
    int Score = 0;
    sort(nums.begin(),nums.end());
    Score = nums[n];
    for(int i=0;i<k-1;i++){
        Score += nums[n]+1;
        nums[n]=nums[n]+1;
    }
    return Score;
}