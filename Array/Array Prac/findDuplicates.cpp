#include<bits/stdc++.h>
using namespace std;


int findDuplicate(vector<int> &arr) 
{
    // Write your code here
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
	
}
