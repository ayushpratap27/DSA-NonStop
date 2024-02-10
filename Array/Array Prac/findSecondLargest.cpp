#include<bits/stdc++.h>
using namespace std;


int findSecondLargest(int n,vector<int> &arr) {
    if(n<2){
        return -1;
    }

    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n; i++){
        if(arr[i] > firstLargest){
            secondLargest = firstLargest;
            firstLargest = arr[i];
        }else if(arr[i] > secondLargest && arr[i] < firstLargest){
            secondLargest = arr[i];
        }
    }

    if(secondLargest == INT_MIN){
        return -1;
    }

    return secondLargest;
}
