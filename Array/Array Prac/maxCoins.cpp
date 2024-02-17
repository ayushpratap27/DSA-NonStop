#include<bits/stdc++.h>
using namespace std;


int maxCoins(vector<int>& piles) {
    sort(piles.begin(),piles.end());
    reverse(piles.begin(),piles.end());
    int ans = 0;
    int i = 1;
    int j = piles.size()-1;
    while(i<j){
        ans += piles[i];
        i += 2;
        j--;
    }
    return ans;
}