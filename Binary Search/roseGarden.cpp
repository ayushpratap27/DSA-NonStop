#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr,int day,int m,int k){
	int cnt=0;
	int nOfB=0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]<=day){
			cnt++;
		}else{
			nOfB+=(cnt/k);
			cnt=0;
		}
	}
	nOfB += (cnt/k);
	return nOfB>=m;
}

int roseGarden(vector<int> arr, int k, int m)
{
	long long val =k*m;
	if(val>arr.size()) return -1;
	int mini=INT_MAX, maxi=INT_MIN;
	for(int i=0;i<arr.size();i++){
		mini=min(mini, arr[i]);
		maxi=max(maxi, arr[i]);
	}
	int low=mini, high=maxi;
	while(low<=high){
		int mid=(low+high)/2;
		if(possible(arr,mid,m,k)){
			high=mid-1;
		}else low=mid+1;
	}
	return low;
}
// Time Complexity = O(N*log(maxi-mini+1))
