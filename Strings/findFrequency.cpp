#include<bits/stdc++.h>
using namespace std;

vector<int> findFrequency(string S) {
    
    vector<int> frequency(26, 0);

    for(char ch:S){
        if(ch>='a' && ch<='z'){
            frequency[ch-'a']++;
        }
    }

    return frequency;
}