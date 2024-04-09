#include<bits/stdc++.h>
using namespace std;

int findSmallestInteger(vector<int> arr){
    int smallest=1; 
    
    for(int i=0;i<arr.size() && arr[i]<=smallest;i++){
        smallest += arr[i]; 
    }
    
    return smallest; 
}