#include<bits/stdc++.h>
using namespace std;

pair<int, int> findSimilarity(vector<int> arr1, vector<int> arr2, int n, int m) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    int common = 0;
    for (int i=0;i<m;i++) {
        if(set1.find(arr2[i]) != set1.end()){
            common++;
        }
    }
    return {common,n+m-common};
}