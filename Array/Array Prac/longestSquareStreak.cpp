#include<iostream>
#include<map>
#include<vector>
using namespace std;

int longestSquareStreak(vector<int>& nums) {
    unordered_map<int, int> mp;
    sort(nums.begin(), nums.end());
    int length = -1;
    for (int num : nums){
        int ele = sqrt(num);
        if (ele * ele == num && mp.find(ele) != mp.end()){
            mp[num] = mp[ele] + 1;
            length = max(length, mp[num]);
        }
        else{
            mp[num] = 1;
        }
    }
    return length;
}