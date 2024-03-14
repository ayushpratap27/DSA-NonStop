#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(const vector<int>& nums, int goal) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0;
    int count = 0;

    for(int num:nums){
        sum+=num;
        if(sum==goal){
            count++;
        }
    
        count += prefixSumCount[sum-goal];

        prefixSumCount[sum]++;
    }

    return count;
}