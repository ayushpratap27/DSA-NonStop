#include<bits/stdc++.h>
using namespace std;

string interpret(string command) {
    int n=command.length();
    string s;
    for(int i=0;i<n;i++){
        if(command[i]=='G'){
            s+='G';
        }else if(command[i]=='(' && command[i+1]==')'){
            s+='o';
        }else if(command[i]=='(' && command[i+1]=='a'){
            s+='a';
            s+='l';
        }
    }
    return s;
}