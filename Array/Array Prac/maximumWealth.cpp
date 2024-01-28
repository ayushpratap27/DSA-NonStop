#include<bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int n=accounts.size();
    int m=accounts[0].size();
    int maxWealth=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=accounts[i][j];
            maxWealth=max(maxWealth,sum);
        }
    }

    return maxWealth;
}