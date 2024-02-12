#include<bits/stdc++.h>
using namespace std;

char findNonRepeating(string s) {
 
    vector<int> v(26);

    for (auto i : s) {
      v[i-'a']++;
    }
    
    for(int i=0;i<s.size();i++){
        if(v[s[i]-'a']==1){
            return s[i];
        }
    }

    return '#';
}