#include <bits/stdc++.h> 
using namespace std;


int getSingleDigitSum(int num) {
    while(num >= 10){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int specialSum(vector<int>& arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return getSingleDigitSum(sum);
}
