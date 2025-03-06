#include<iostream>
#include<vector>
using namespace std;


// Brute force which is not a sliding window
vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    bool flag = true;
    for (int i = 0; i < n - k + 1; i++){
        for (int j = i; j < i + k - 1; j++){
            if (nums[j + 1] != nums[j] + 1)
                flag = false;
        }
        if (flag){
            int maxi = INT_MIN;
            for (int z = i; z < i + k; z++){
                maxi = max(maxi, nums[z]);
            }
            ans.push_back(maxi);
            flag = true;
        }
        else{
            ans.push_back(-1);
            flag = true;
        }
    }

    return ans;
}

// Sliding window approach

vector<int> resultsArray(vector<int> &nums, int k){
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i <= n - k; i++){
        int mx = INT_MIN;
        bool isSequential = true;

        for (int j = i; j < i + k; j++){
            mx = max(mx, nums[j]);

            if (i < j && nums[j] != nums[j - 1] + 1){
                isSequential = false;
            }
        }

        if (isSequential){
            ans.push_back(mx);
        }
        else{
            ans.push_back(-1);
        }
    }

    return ans;
}