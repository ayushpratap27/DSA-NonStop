#include<bits/stdc++.h>
using namespace std;

int minimumDeletions(string s) {
    int n = s.size();
    vector<int> f(n + 1,0);
    int countB = 0;
        
    for(int i=1;i<=n;i++) {
        if(s[i-1] == 'b') {
            f[i] = f[i-1];
            countB++;
        } else {
            f[i] = min(f[i-1] + 1, countB);
        }
    }
        
    return f[n];
}