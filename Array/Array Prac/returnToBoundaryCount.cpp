#include<bits/stdc++.h>
using namespace std;


int returnToBoundaryCount(vector<int>& nums) {
        int count =0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum==0){
                count++;
            }
        }
        return count;
}