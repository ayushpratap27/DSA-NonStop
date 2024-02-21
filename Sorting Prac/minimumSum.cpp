#include<bits/stdc++.h>
using namespace std;


int minimumSum(int num) {
    vector<int> v;
    while(num){
        v.push_back(num%10);
        num=num/10;
    }

    sort(v.begin(),v.end());
        
    int new1=v[0]*10 + v[2];
    int new2=v[1]*10 + v[3];

    return new1+new2;

}