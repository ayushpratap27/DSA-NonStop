#include<bits/stdc++.h>
using namespace std;

int arraySign(vector<int>& nums) {
    int zeros=0;
    int negative=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            zeros++;
            break;
        }
        else if(nums[i]<0){
            negative++;
        }
    }
    if(zeros!=0){
        return 0;
    }else if(negative%2!=0){
        return -1;
    }else{
        return 1;
    }
}