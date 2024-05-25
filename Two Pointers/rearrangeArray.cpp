#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& a) {
    int n=a.size();
    vector<int> v(n);
    int p=0,q=1;
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            v[p]=a[i];
            p=p+2;
        }
    }
    for(int j=0;j<n;j++){
        if(a[j]<0){
            v[q]=a[j];
            q=q+2;
        }
    }

    return v;
        
}