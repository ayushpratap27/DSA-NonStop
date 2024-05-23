#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {
    int n = v.size();
    int candidate = v[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] == candidate) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidate = v[i];
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int majorityElement(vector<int> v) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = v.size();
    int cnt=0;
    int ele;

    for(int i=0;i<n;i++){
        if(cnt==0){
            ele=v[i];
            cnt=1;
        }else if(v[i]==ele){
            cnt++;
        }else{
            cnt--;
        }
    }
    
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(v[i]==ele){
            cnt1++;
        }
    }
    if(cnt1>(n/2)){
        return ele;
    }
    return -1;
}
//  T.C.=O(n)   S.C.=O(1)