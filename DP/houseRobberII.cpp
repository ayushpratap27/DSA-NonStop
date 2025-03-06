#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for(int i=1;i<n;i++){
        int take = nums[i];
        if(i > 1) take += prev2;

        int nonTake = 0 + prev;

        int curr_i = max(take, nonTake);
        prev2 = prev;
        prev = curr_i;
    }

    return prev;
}

int rob(vector<int>& ValueInHouse) {
    int n = ValueInHouse.size();
    if(n == 1) return ValueInHouse[0];
    vector<int> temp1, temp2;

    for(int i=0;i<n;i++){
        if(i !=0) temp1.push_back(ValueInHouse[i]);
        if(i != n-1) temp2.push_back(ValueInHouse[i]);
    }

    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));

}