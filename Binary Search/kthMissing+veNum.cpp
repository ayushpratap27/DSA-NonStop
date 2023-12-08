#include<bits/stdc++.h>
using namespace std;

int missingK(vector<int>& arr, int n, int k) {
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int missing=arr[mid]-(mid+1);

            if(missing<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return k+high+1;
        
        
}
//return low+k;

//time complexity= O(logn)

// ans=arr[high]+more where more=(k-missing)
// ans=arr[high]+k-arr[high]+high+1
// ans=k+high+1
// ans=k+low   