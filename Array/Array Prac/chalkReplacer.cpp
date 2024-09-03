#include<bits/stdc++.h>
using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    int n = chalk.size();
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += chalk[i];
    }
    k = k%sum;
    for(int i=0;i<n;i++){
        if(chalk[i] > k){
            return i;
        }
        k -= chalk[i];
    }

    return -1;
}

//  Time Complexity :- O(n)
//  Space Complexity :- O(1)