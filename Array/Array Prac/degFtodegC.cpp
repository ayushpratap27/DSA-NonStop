#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fahrenheitToCelsius(int s, int e, int w){

    //C=5*(F-32)/9
    
	int n = (e-s)/w;
	vector<vector<int>> v;
	for (int i=0; i<=n ;i++) {
        v.push_back({s+i*w, (((s + i * w) - 32) * 5) / 9});
    }

    return v;
}