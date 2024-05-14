#include<bits/stdc++.h>
using namespace std;

//************* Brute Force *******************

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    vector<pair<double, pair<int,int>>> fractions;
    int n=arr.size();

    for(int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            double fraction = (double)arr[i] / arr[j];
            fractions.push_back({fraction, {i,j}});
        }
    }

    sort(fractions.begin(), fractions.end());

    auto indices = fractions[k-1].second;

    return {arr[indices.first], arr[indices.second]};
}

//************* Best- Using binary search*****************

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    double left = 0, right = 1, mid;
    vector<int> res;

    while (left <= right) {
        mid = left + (right - left) / 2;
        int j = 1, total = 0, num = 0, den = 0;
        double maxFrac = 0;
        for (int i = 0; i < n; ++ i) {
            while (j < n && arr[i] >= arr[j] * mid) {
                ++j;
            }
            
            total += n - j;

            if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                maxFrac = arr[i] * 1.0 / arr[j];
                num = i; den = j;
            }
        }

        if (total == k) {
            res = {arr[num], arr[den]};
            break;
        }

        if (total > k) {
            right = mid;
        } else {
            left = mid;
        }
    }

    return res;

}