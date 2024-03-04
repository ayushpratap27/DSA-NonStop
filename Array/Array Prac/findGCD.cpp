#include<bits/stdc++.h>
using namespace std;

int findGCD(vector<int>& nums) {
    int mini = *min_element(nums.begin(),nums.end());
    int maxi = *max_element(nums.begin(),nums.end());

    return __gcd(mini, maxi);
}