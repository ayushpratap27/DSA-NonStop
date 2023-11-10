#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> &nums,int low,int high,int target){
    //Recursively
    if(low>high) return -1;//base case
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    else if(target>nums[mid]) return bs(nums, mid+1, high, target);

    return bs(nums,low,mid-1,target);

}

int search(vector<int>&nums,int target){
    return bs(nums,0,nums.size()-1,target);
}

//int search(vector<int> &nums, int target) {
  //  int n=nums.size();
    //***********linear search*********
    // for(int i=0;i<n;i++){
    //     if(nums[i]==target){
    //         return i;
    //     }
    // }

    //***********binary search--> iterative**********
    // int low=0,high=n-1;
    // while(low<=high){
    //     int mid=(low+high)/2;
    //     if(nums[mid]==target) return mid;
    //     else if(target>nums[mid]) low=mid+1;
    //     else high=mid-1;
    // }


    //return -1;
//}