#include<bits/stdc++.h>
using namespace std;

int computeXOR(int n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0;
}

int findXOR(int L, int R) {
    // XOR of [0, R] XOR [0, L-1]
    return computeXOR(R) ^ computeXOR(L - 1);
}