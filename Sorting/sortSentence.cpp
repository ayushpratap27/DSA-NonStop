#include<bits/stdc++.h>
using namespace std;

string sortSentence(string s){
    stringstream ss(s);
    string word;
    vector<pair<int,string>>words;

    while(ss>>word){
        int index=word.back() - '0';
        word.pop_back();
        words.push_back({index, word});
    }

    sort(words.begin(),words.end());

    string org_sentence;
    for(const auto& pair : words){
        org_sentence += pair.second + " ";
    }

    if(!org_sentence.empty()){
        org_sentence.pop_back();
    }

    return org_sentence;
}      