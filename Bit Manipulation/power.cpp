#include<bits/stdc++.h>
using namespace std;

double myPow(double x,long long int n) {
    // if (n == 0) return 1.0;
    // if (n < 0) {
    //     x = 1.0 / x;
    //     n = -n;
    // }
    // double result = 1.0;
    // while (n > 0) {
    //     if (n % 2 == 1) {
    //         result *= x;
    //     }
    //     x *= x;
    //     n /= 2;
    // }

    double result=pow(x,n);

    return result;
}