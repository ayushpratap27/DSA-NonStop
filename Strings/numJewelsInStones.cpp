#include<bits/stdc++.h>
using namespace std;



int numJewelsInStones(string jewels, string stones) {
    int n=stones.size();
    int m=jewels.size();
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(stones[j]==jewels[i]){
                count++;
            }
        }
    }

    return count;
}