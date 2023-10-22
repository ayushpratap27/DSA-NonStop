#include<bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int> &v){
    int n=v.size();
    int m=INT_MIN;
    int x=INT_MIN;
    for(int i=0; i<n; i++){
        if(v[i]>m){
            m=v[i];
        }
    }
    m=-1;
    for(int i=0;i<n;i++){
        if(v[i]>n){
            n=v[i];
        }
    }

    return n;
}