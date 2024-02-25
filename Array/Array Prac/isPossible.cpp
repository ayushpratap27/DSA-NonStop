#include<bits/stdc++.h>
using namespace std;


bool isPossible(int *arr, int n) {
    int count = 0;

    for (int i=1;i<n;i++) {
        if (arr[i]<arr[i-1]){
            count++;
            if(count>1){
                return false;
            }

            if(i>=2 && arr[i]<arr[i-2]){
                arr[i] = arr[i-1];
            }else{
                arr[i-1] = arr[i];
            }
        }
    }

    return true;
}