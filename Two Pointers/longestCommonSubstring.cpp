#include<bits/stdc++.h>
using namespace std;

int longestRepeatingSubstring(string &s, int k) {
    int n = s.length();
    vector<int> count(26,0);
    int maxCount=0; 
    int maxLength=0; 

    int j=0; 
    for(int i=0;i<n;i++){
        maxCount = max(maxCount,++count[s[i]-'A']); 

        while(i-j+1-maxCount>k){
            count[s[j]-'A']--; 
            j++;
        }

        maxLength=max(maxLength,i-j+1);
    }

    return maxLength;
}