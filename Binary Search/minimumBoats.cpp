#include<bits/stdc++.h>
using namespace std;

int minimumBoats(vector<int> &arr, int l) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int boats = 0;
    int left = 0, right = n - 1;
    
    while (left <= right) {
        if (arr[left] + arr[right] <= l) {
            left++;
            right--;
        } else {
            right--;
        }
        boats++;
    }
    return boats;
}