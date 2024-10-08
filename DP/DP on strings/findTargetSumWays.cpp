#include<bits/stdc++.h>
using namespace std;

int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<int> prev(k+1,0), curr(k+1,0);
	if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

	if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;
	for(int ind=1;ind<n;ind++){
		for(int sum=0;sum<=k;sum++){
			int notTake = prev[sum];
			int take = 0;
			if(arr[ind] <= sum) take = prev[sum-arr[ind]];
			curr[sum] = (take + notTake);
		}
        prev = curr;
	}

	return prev[k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(int i=0;i<n;i++) totalSum += arr[i];
    if(totalSum-d < 0 || (totalSum-d) % 2) return false;

    return findWays(arr, (totalSum - d)/2);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    return countPartitions(n, target, nums);
}