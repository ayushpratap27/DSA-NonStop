#include <bits/stdc++.h> 
using namespace std;


bool possibleToMakeTriangle(std::vector<int> &arr) {
    if (arr.size() < 3) {
        return false;
    }
    
    sort(arr.begin(), arr.end());
    
    for (int i=0;i<arr.size()-2;i++){
        if (arr[i] + arr[i+1] > arr[i+2]) {
            return true; 
        }
    }

    return false;  
}
