#include<bits/stdc++.h>
using namespace std;


int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    long long pro=1;
    int i=0,j=0;
    int count=0;
    while(i<nums.size()){
        j=i;   
        while( j<nums.size()){
            pro*=nums[j];
            if(pro<k){
            count++;  
            j++;
            }else{
                break;
            }
        }
        i++;
        pro=1;
    }
    return count;
}