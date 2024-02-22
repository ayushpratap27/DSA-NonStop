#include<bits/stdc++.h>
using namespace std;

int sparseSearch(vector<string>& arr, string& k) {
	for(int i=0;i<arr.size();i++){
		if(arr[i]==k){
			return i;
		}
	}
	return -1;
}