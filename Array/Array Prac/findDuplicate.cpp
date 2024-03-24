#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            result.push_back(nums[i]);
        }
    }
    return result;
}

// int findDuplicate(vector<int>& nums) {
//     int slow=nums[0];
//     int fast=nums[0];

//     do{
//         slow= nums[slow];
//         fast= nums[nums[fast]];
//     } while(slow!=fast);

//     slow=nums[0];
//     while(slow!=fast) {
//         slow=nums[slow];
//         fast=nums[fast];
//     }

//     return slow;
// }