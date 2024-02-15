#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int min = prices[0];
    for(int i=1;i<prices.size();i++){
        int temp = prices[i]-min;
        ans = max(ans,temp);
        if(prices[i]<min){
            min = prices[i];
        }
    }
    return ans;
}