#include<bits/stdc++.h>
using namespace std;

vector<int> findWordsContaining(vector<string>& words, char x) {
    int n = words.size();
    vector<int> idx;
    for(int i=0;i<n;i++){
        if(words[i].find(x)!=string::npos){
            idx.push_back(i);
        }
    }

    return idx;
    
}