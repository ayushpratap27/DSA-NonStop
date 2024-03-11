#include<bits/stdc++.h>
using namespace std;

int mostWordsFound(vector<string>& sentences) {
    int n=sentences.size();
    int count=0;
    for(int i=0;i<n;i++){
        string s=sentences[i];
        int cnt=0;
        for(int j=0;j<s.size();j++){
            if(s[j]==' '){
                cnt++;
            }
        }
        count=max(count,cnt);
    }

    return count+1;
}