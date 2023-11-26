#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    // Check if n is positive and has only one bit set to 1
    return n > 0 && (n & (n - 1)) == 0;
}