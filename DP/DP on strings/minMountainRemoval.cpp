#include<bits/stdc++.h>
using namespace std;

int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);

        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                if(nums[prev] < nums[ind] && dp1[prev] + 1 > dp1[ind]){
                    dp1[ind] = dp1[prev] + 1;
                }
            }
        }

        for(int ind = n - 1; ind >= 0; ind--){
            for(int prev = n - 1; prev > ind; prev--){
                if(nums[prev] < nums[ind] && dp2[prev] + 1 > dp2[ind]){
                    dp2[ind] = dp2[prev] + 1;
                }
            }
        }

        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(dp1[i] > 1 && dp2[i] > 1){ 
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }

        return n - maxi;
}