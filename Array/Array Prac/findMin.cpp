#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    int low=0, high=arr.size()-1;
    
    while(low<high){
        int mid=(low+high)/2 ;
        if(arr[mid]<arr[high]){
            high=mid;
        }else if(arr[mid]>arr[high]){
            low=mid+1;
        }else {
            high--;
        }
    }

    return arr[low];        

}