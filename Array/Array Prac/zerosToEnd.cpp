#include<bits/stdc++.h>
using namespace std;

    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int j=0;
            bool flag=false;
            while(j!=i){
                if(nums[j]==0 && nums[j+1]!=0){
                    swap(nums[j],nums[j+1]);
                    flag=true;
                }
                j++;
            }
            if(!flag) break;
        
        }
        
    }
