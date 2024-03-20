#include<bits/stdc++.h>
using namespace std;

vector<long long> findPrefixScore(vector<int>& arr) {
    long long maxi=0,n=arr.size(),ans=0;
    vector<long long> res(n);
    for(int i=0;i<n;i++){
        maxi=max(maxi,(long long)arr[i]);
        long long sum=arr[i]+maxi;
        ans+=sum;
        res[i]=ans;
    }
    
    return res;
}