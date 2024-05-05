#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int maximumSum(vector<int> &a, int n) {

    sort(a.begin(), a.end());

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + (long long)a[i] * i) % MOD;
    }
    return sum;
}