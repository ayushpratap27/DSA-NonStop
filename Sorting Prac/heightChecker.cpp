#include<bits/stdc++.h>
using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> v(heights.begin(),heights.end());
    int count=0;
    sort(heights.begin(),heights.end());
    for(int i=0;i<heights.size();i++){
        if(heights[i]!=v[i]){
            count++;
        }
    }
    return count;
}