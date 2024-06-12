#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    for(auto it : mp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}
//  T.C. = O(n) + O(m)
//  S.C. = O(m), where m = n/3 + 1

int singleNumber(vector<int> &nums){
    int ans = 0;
    for(int bitIndex=0;bitIndex<32;bitIndex++){
        int cnt = 0;
        for(int j=0;j<nums.size();j++){
            if(nums[j] & (1 << bitIndex)){
                cnt++;
            } 
        }

        if(cnt%3 == 1){
            ans = ans | (1 << bitIndex);
        }
    }

    return ans;
}

//  T.C. = O(n*32)
//  S.C. = O(1)


//******* Better than previous ********
int singleNumber(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());

    for(int i=1;i<n;i+=3){
        if(nums[i] != nums[i-1]){
            return nums[i-1];
        }
    }

    return nums[n-1];
}
//  T.C. = O(nlogn) + O(n/3)
//  S.C. = O(1)

//******** Optimal Solution ***********/
int singleNumber(vector<int> &nums){
    int ones = 0;
    int twos = 0;
    for(int i=0;i<nums.size();i++){
        ones = (ones^nums[i]) & ~twos;
        twos = (twos^nums[i]) & ~ones;
    }

    return ones;
}
//  T.C. = O(n)   S.C. = O(1)