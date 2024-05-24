#include<bits/stdc++.h>
using namespace std;

//*********** Brute Force ***************
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> st;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> result(st.begin(),st.end());
    return result;
}
// T.C.=O(n^3 * log(no. of unique triplets))
// S.C.=O(2*number of triplets)

