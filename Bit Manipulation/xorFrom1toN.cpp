#include<bits/stdc++.h>
using namespace std;


int xorFrom1ToN(int n){
    if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else return n;
}
// T.C. = O(1)  S.C. = O(1)

int xorFromLtor(int l,int r){
    return xorFrom1ToN(l-1) ^ xorFrom1ToN(r);
}