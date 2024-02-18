#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int n = g.size();
    int m = s.size();
    int count = 0;
    int i=0,j=0;
    while(i<n && j<m){
        if(s[j]>=g[i]){
            count++;
            i++;
            j++;
        }
        else if(g[i]>s[i]){
            j++;
        }
    }
    return count;
}