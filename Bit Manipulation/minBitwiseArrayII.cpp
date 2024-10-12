#include <bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++){
        int curr = nums[i];
        int tempAns = INT_MAX;
        bool found = false;

        for (int bit = 0; bit < 31; bit++){
            if ((curr >> bit) & 1){
                int x = curr & ~(1 << bit);
                if (x < 0)
                    continue;

                if ((x | (x + 1)) == curr){
                    if (x < tempAns){
                        tempAns = x;
                        found = true;
                    }
                }
            }
        }

        if (found){
            ans[i] = tempAns;
        }
        else{
            ans[i] = -1;
        }
    }

    return ans;
}

