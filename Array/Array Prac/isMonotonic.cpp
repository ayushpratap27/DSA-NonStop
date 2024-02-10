#include<bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int>& nums) {
    int x=0,y=0;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            x++;
            y++;
        }
        else if(nums[i]<nums[i+1]){
            x++;
        }
        else{
            y++;
        }
    }
    if(x==nums.size()-1 || y==nums.size()-1){
        return true;
    } 
        
    return false;
            
}