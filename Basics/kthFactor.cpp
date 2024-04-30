#include<bits/stdc++.h>
using namespace std;

int kthFactor(int n, int k) {
    if (k == 1) return 1;

    int sqrtN = sqrt(n);
    for(int i = 1; i <= sqrtN; i++) {
        if(n % i == 0) {
            k--;
            if(k == 0) return i;
        }
    }

    if(sqrtN * sqrtN == n) sqrtN--;
    for(int i = sqrtN; i >= 1; i--) {
        if(n % i == 0) {
            k--;
            if(k == 0) return n / i;
        }
    }

    return -1;
}