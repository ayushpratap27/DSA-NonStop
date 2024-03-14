#include<bits/stdc++.h>
using namespace std;

int pivotInteger(int n) {
    int left=1, right= n;
    int fullSum = (n*(n+1))/2;
    while(left<=right){
        int mid = left + (right-left)/2;
        int LHS = (mid*(mid+1))/2;
        int RHS = fullSum - LHS + mid;
        if(LHS == RHS){
            return mid;
        }
        else if(LHS < RHS){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
    }