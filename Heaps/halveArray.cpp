#include <bits/stdc++.h>
using namespace std;

int halveArray(vector<int> &nums){
    int n = nums.size();
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += nums[i];
    }

    priority_queue<double> pq(nums.begin(), nums.end());
    double currentSum = sum;
    int count = 0;

    while (currentSum > sum / 2){
        double top = pq.top();
        pq.pop();

        currentSum -= top / 2;
        pq.push(top / 2);

        count++;
    }

    return count;
}