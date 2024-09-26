#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int> &cardPoints, int k){
    int n = cardPoints.size();
    int lsum = 0, rsum = 0, maxSum = 0;
    for (int i = 0; i < k; i++){
        lsum += cardPoints[i];
    }
    maxSum = lsum;
    for (int i = k - 1, rightIdx = n - 1; i >= 0; i--, rightIdx--){
        lsum = lsum - cardPoints[i];
        rsum = rsum + cardPoints[rightIdx];
        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}