#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0,high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		//maybe an answer
		if(arr[mid]>=x){
			ans=mid;
			//look for more small index on left
			high=mid-1;
		}
		else{
			low=mid+1;//look for right
		}
	}

	return ans;
}

int upperBound(vector<int> &arr, int n, int x){
	// Write your code here.
	int low=0,high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}	

	return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int lb=lowerBound(arr, n ,k);
	if(lb==n || arr[lb]!=k) return {-1,-1};
	return {lb, upperBound(arr, n, k)-1};
}



int count(vector<int>& arr, int n, int x) {
	pair<int,int> ans= firstAndLastPosition(arr, n, x);
	if(ans.first==-1) return 0;
	return ans.second-ans.first +1;
}
