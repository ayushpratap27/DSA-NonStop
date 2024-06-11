#include<bits/stdc++.h>
using namespace std;


int minBitFlipsToConvertNum(int start, int goal) {
    int xorResult = start ^ goal;
    int cnt = 0;

    while (xorResult) {
        cnt += xorResult & 1;
        xorResult >>= 1;
    }

    return cnt;
}


int main(){
    int result = minBitFlipsToConvertNum(3,4);

    cout<<result<<endl;
}
// T.C. = log(start ^ goal)
// S.C. = O(1)