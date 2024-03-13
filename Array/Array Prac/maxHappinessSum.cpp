#include<bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k) {
    int n = happiness.size();
    
    long long maxHappy = 0;
    sort(happiness.begin(), happiness.end(), greater<int>());
    for(int i = 0; i < n; i++) {
        if(happiness[i] <= i) break;
        if(k == 0) break;
        maxHappy += happiness[i] - i;
        k--;
    }
    
    return maxHappy;
}