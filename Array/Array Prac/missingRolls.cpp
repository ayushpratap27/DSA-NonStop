#include<bits/stdc++.h>
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    vector<int> v(n,0);
        
    int sumOfn = 0;
    int sum = 0;
    for(int i=0;i<m;i++){
        sum += rolls[i];
    }
    sumOfn = mean*(m+n) - sum;
    if(sumOfn < n || sumOfn > 6*n){
        return {};
    }

    int baseValue = sumOfn / n;       
    int remaining = sumOfn % n;       

    for(int i=0;i<n;i++){
        v[i] = baseValue;      
    }

    for(int i=0;i<remaining;i++){
        v[i] += 1;
    }

    return v;

}