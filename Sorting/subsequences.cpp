#include<bits/stdc++.h>
using namespace std;
 
void generateSubsequences(string str, int index, string current, vector<string> &result){
    if(index==str.length()){
        if(!current.empty()){
            result.push_back(current);
        }
        return;
    }

    generateSubsequences(str, index+1, current+str[index], result);
    generateSubsequences(str, index+1, current, result);
}

vector<string> subsequences(string str){
    vector<string> result;
    generateSubsequences(str, 0, "", result);
    return result;
}
