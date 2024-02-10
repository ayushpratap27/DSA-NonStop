#include<bits/stdc++.h>
using namespace std;

int findLUSlength(string a, string b) {
    int longestSubsequence = -1;
    int i=0;
    int count = 0;

    if(a!=b){
        return max(a.size(),b.size());
    }
        
    while(i<a.length()){
        if(a[i]!=b[i]){
            count++;
        }
        else{
            longestSubsequence = max(longestSubsequence,count);
            count = 0;
        }
        i++;
    }

    if(longestSubsequence == 0){
        return -1;
    }
    else{
        return count;
    }

}