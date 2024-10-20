#include <bits/stdc++.h>
using namespace std;

string invert(string str){
    int n = str.size();
    for (int i = 0; i < n; i++){
        if (str[i] == '0'){
            str[i] = '1';
        }
        else{
            str[i] = '0';
        }
    }

    return str;
}

char findKthBit(int n, int k){
    string str = "0";
    while (str.size() < k){
        string temp = invert(str);
        reverse(temp.begin(), temp.end());
        str = str + "1" + temp;
    }
    return str[k - 1];
}