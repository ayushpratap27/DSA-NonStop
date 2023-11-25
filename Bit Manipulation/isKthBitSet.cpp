#include<bits/stdc++.h>
using namespace std;


bool isKthBitSet(int N, int K) {
    // Shifting 1 to the left by K-1 positions
    // and performing bitwise AND with N
    // If the result is not zero, then the Kth bit is set
    return (N & (1 << (K - 1))) != 0;
}