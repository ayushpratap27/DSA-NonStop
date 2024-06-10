#include<bits/stdc++.h>
using namespace std;

string convertToBinary(int n){
    string res = "";
    while(n != 1){
        if(n%2 == 1){
            res += '1';
        }else{
            res += '0';
        }
        n = n/2;
    }
    reverse(res.begin(),res.end());

    return res;
}
//  T.C. = log(n)   S.C. = log(n)

