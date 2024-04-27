#include <bits/stdc++.h>>
using namespace std;


string reverseStringWordWise(string input){
    vector<string> words;
    stringstream ss(input);
    string word;

    while(ss>>word){
        words.push_back(word);
    }

    string reversedString;

    for(int i=words.size()-1;i>=0;i--){
        reversedString += words[i];
        if(i!=0) {
            reversedString += " ";
        }
    }

    return reversedString;
}

int main(){
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}