#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k) return mid;

        //identify sorted half
        if(arr[low]<=arr[mid]){
            //left sorted
            if(arr[low]<=k && k<=arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            //right sorted
            if(arr[mid]<=k && k<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }

    return -1;
}
