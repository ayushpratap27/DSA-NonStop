#include<bits/stdc++.h>
using namespace std;

string sortVowels(string s) {
    string vowels;
    for(int i=0;i<s.length();i++){
        if(s[i]=='A'||s[i]=='a'||s[i]=='E'||s[i]=='e'||s[i]=='I'||s[i]=='i'||s[i]=='O'||s[i]=='o'||s[i]=='U'||s[i]=='u'){
            vowels.push_back(s[i]);
        }
    }
    sort(vowels.begin(),vowels.end());
    string res;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'||s[i]=='a'||s[i]=='E'||s[i]=='e'||s[i]=='I'||s[i]=='i'||s[i]=='O'||s[i]=='o'||s[i]=='U'||s[i]=='u'){
            res.push_back(vowels[j]);
            j++;
        }
        else{
            res.push_back(s[i]);
        }
    }

    return res;
        
}