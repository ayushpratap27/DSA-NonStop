#include <bits/stdc++.h> 
using namespace std;


int numberofSubarrays(vector<int> &arr, int n) {
    int ones = 0; 
    int zeros = 0; 
    int ans = 0; 

    for (int i = 0; i < n; ++i) {
        if (arr[i] == 1) {
            ones++;
            ans += ones;
        } else {
            ones = 0;
        }

        if (arr[i] == 0) {
            zeros++;
            ans += zeros;
        } else {
            zeros = 0;
        }
    }

    return ans;
}
