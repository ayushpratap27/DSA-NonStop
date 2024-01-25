#include<bits/stdc++.h>
using namespace std;


vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(arr.begin(),arr.end());

	vector<int> result;
	result.push_back(arr[k-1]);
	result.push_back(arr[n-k]);

	return result;
}