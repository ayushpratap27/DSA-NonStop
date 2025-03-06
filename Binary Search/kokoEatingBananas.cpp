#include<bits/stdc++.h>
using namespace std;

// int minEatingSpeed(vector<int>& piles, int h) {
//     // Binary search to find the minimum eating speed
//     int left = 1;
//     int right = *max_element(piles.begin(), piles.end());

//     while (left < right) {
//         int mid = left + (right - left) / 2;

//         int hoursRequired = 0;
//         for (int pile : piles) {
//             hoursRequired += (pile + mid - 1) / mid;  // Ceil division
//         }

//         if (hoursRequired > h) {
//             // If it takes more hours than allowed, increase eating speed
//             left = mid + 1;
//         } else {
//             // If it takes fewer hours or exactly h, decrease eating speed
//             right = mid;
//         }
//     }

//     return left;
// }

bool isPossible(vector<int> &piles, int h, int x){
    long long hour = 0;
    for (long long bananas : piles){
        hour += bananas / x;
        if (bananas % x)
            hour++;
        if (hour > h)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h){
    int n = piles.size();
    long long left = 1;
    long long right = *max_element(piles.begin(), piles.end());
    long long ans = -1;
    while (left <= right){
        long long mid = (left + right) / 2;
        if (isPossible(piles, h, mid)){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return ans;
}