#include<bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int>& nums) {
    long long n=0;
    long long cnt=0;
    
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            cnt++;
        }
        else{
            n += (cnt*(cnt+1)/2);
            cnt = 0;
        }
    }

    if(cnt>0){
        n += (cnt*(cnt+1)/2);
    }

    return n;

}