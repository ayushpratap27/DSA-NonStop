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

//************* Better Approach ***************
vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(nums[i]+nums[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int> temp={nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }

    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// T.C.=O(n^2 * log(size of set(variable)))
// S.C.=O(n) + O(2*no. of unique triplets)