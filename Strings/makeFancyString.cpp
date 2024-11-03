#include<iostream>
#include<vector>
#include<string>
using namespace std;

string makeFancyString(string s) {
    string result;
    int count = 1;
    result.push_back(s[0]);

    for (int i = 1; i < s.size(); i++){
        if (s[i] == s[i - 1]){
            count++;
        }
        else{
            count = 1;
        }

        if (count <= 2){
            result.push_back(s[i]);
        }
    }

    return result;
}