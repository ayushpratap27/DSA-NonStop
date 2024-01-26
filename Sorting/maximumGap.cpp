#include<bits/stdc++.h>
using namespace std;;

int maximumGap(vector<int>& nums) {
    int n=nums.size();
    int difference=0;
    
    sort(nums.begin(),nums.end());

    if(n<2)
    return 0;

    for(int i=1;i<n;i++){
        difference=max(difference,nums[i]-nums[i-1]);
    }

    return difference;
}