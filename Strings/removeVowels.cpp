#include<bits/stdc++.h>
using namespace std;

string removeVowels(string inputString) {
    string result = "";
    for(char c : inputString){
        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
            c!='A' && c!='E' && c!='I' && c!='O' && c!='U'){
            result += c;
        }
    }
    return result;
}