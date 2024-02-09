#include<bits/stdc++.h>
using namespace std;


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    set<int> s;
    
    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums1[i]==nums2[j] ){
                s.insert(nums2[j]);
            }
        }
    }

    vector<int> result(s.begin(),s.end());

    return result;

}