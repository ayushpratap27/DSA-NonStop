#include<bits/stdc++.h>
using namespace std;


int numIdenticalPairs(vector<int>& nums) {

    int goodPairs = 0;

    for(int i=0;i<nums.size();i++){

        for(int j=0;j<nums.size();j++){

            if(nums[i]==nums[j] && i<j){

                goodPairs++;
                
            }

        }
    }


    return goodPairs;
}