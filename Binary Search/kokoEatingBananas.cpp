#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    // Binary search to find the minimum eating speed
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left < right) {
        int mid = left + (right - left) / 2;

        int hoursRequired = 0;
        for (int pile : piles) {
            hoursRequired += (pile + mid - 1) / mid;  // Ceil division
        }

        if (hoursRequired > h) {
            // If it takes more hours than allowed, increase eating speed
            left = mid + 1;
        } else {
            // If it takes fewer hours or exactly h, decrease eating speed
            right = mid;
        }
    }

    return left;
}