#include<bits/stdc++.h>
using namespace std;

vector<int> sortEvenOdd(vector<int>& nums) {
    if(nums.size()<=2){
        return nums;
    }
    vector<int> ans;
    vector<int> odd;
    vector<int> even;
    for(int i=0;i<nums.size();i++){
        if(i%2==0){
            even.push_back(nums[i]);
        }
        else{
            odd.push_back(nums[i]);
        }
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    reverse(odd.begin(),odd.end());
    for(int i=0;i<even.size();i++){
        if(ans.size()==nums.size()) break;
        if(ans.size()<nums.size()){
            ans.push_back(even[i]);
        }
        if(ans.size()<nums.size()){
            ans.push_back(odd[i]);
        }
    }
    return ans;
}