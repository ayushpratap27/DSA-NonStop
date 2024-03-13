#include<bits/stdc++.h>
using namespace std;

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    int m=capacity.size();
    sort(capacity.begin(),capacity.end());

    int totalApples=accumulate(apple.begin(),apple.end(),0);
    
    int sum=0;
    int count=0;
    for(int i=m-1;i>=0;i--){
        sum+=capacity[i];
        count++;
        if(sum>=totalApples){
            break;
        }
    }

    return count;
}