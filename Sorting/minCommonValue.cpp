#include<bits/stdc++.h>
using namespace std;

int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //given arrays are sorted 
    int n=nums1.size();
    int m=nums2.size();
    int ans=-1;
    int i=0,j=0;
    while(i<n && j<m){
        if(nums1[i]==nums2[j]){
            ans=nums1[i];
            break;
        }
        if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}