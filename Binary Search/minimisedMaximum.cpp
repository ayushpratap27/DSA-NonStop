#include<iostream>
#include<vector>
using namespace std;

bool isPossible(int n, vector<int> &quantities, int x){
    int stores = 0;
    for (int quantity : quantities){
        stores += quantity / x;
        if (quantity % x)
            stores++;
        if (stores > n)
            return false;
    }
    return true;
}

int minimizedMaximum(int n, vector<int> &quantities){
    int left = 1;
    int right = *max_element(quantities.begin(), quantities.end());
    int ans = -1;

    while (left <= right){
        int mid = (left + right) / 2;
        if (isPossible(n, quantities, mid)){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return ans;
}