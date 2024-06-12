#include<bits/stdc++.h>
using namespace std;

int divideTwoIntegers(int dividend,int divisor){
    int sum = 0;
    int cnt = 0;

    while(sum + divisor <= dividend){
        cnt += 1;
        sum += divisor;
    }

    return cnt;
}

// T.C. = O(dividend)  S.C. = O(1)
// It will give TLE

int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if(dividend == INT_MIN && divisor == 1){
        return -2147483648;
    }

    bool sign = (dividend < 0) == (divisor < 0);

    long n = labs(dividend);
    long d = labs(divisor);
    long quotient = 0;

    while (n >= d) {
        int cnt = 0;
        while (n >= (d << (cnt + 1))) {
            cnt++;
            if (d << (cnt + 1) > n) break;
        }

        quotient += (1 << cnt);
        n -= (d << cnt);
    }

    quotient = sign ? quotient : -quotient;

    if (quotient > INT_MAX) {
        return INT_MAX;
    } else if (quotient < INT_MIN) {
        return INT_MIN;
    }

    return static_cast<int>(quotient);
}
/*The time complexity of this divide function is O(log(n)), where n is the
absolute value of the dividend. This is because the function repeatedly divides the 
dividend by the divisor in a loop until the dividend is less than the divisor, effectively 
performing a binary search to find the quotient.
*/
//  S.C. = O(1)