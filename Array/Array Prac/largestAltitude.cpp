#include<bits/stdc++.h>
using namespace std;


int largestAltitude(vector<int>& gain) {
    int n=gain.size();
    int height=0;
    int maxGain=0;
    for(int i=0;i<n;i++){
        height+=gain[i];
        maxGain=max(maxGain,height);
    }

    return maxGain;

}