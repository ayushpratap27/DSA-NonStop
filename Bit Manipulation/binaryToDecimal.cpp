#include<bits/stdc++.h>
using namespace std;

int convertToDecimal(string x){
    int n = x.length(), p2 = 1, num = 0;

    for(int i = n-1;i >= 0;i--){
        if(x[i] == '1'){
            num = num + p2;
            p2 = p2*2;
        }
    }

    return num;
}
//  T.C. = O(n)   S.C. = O(1)