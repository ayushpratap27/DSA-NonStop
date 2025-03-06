#include <iostream>
using namespace std;

bool f(int n, int k){
    int ans = 1;
    while (n > 0){
        ans *= n % 10;
        n = n / 10;
    }

    if (ans % k == 0)
        return true;

    return false;
}
int smallestNumber(int n, int t){
    while (true){
        if (f(n, t))
            return n;
        else
            n++;
    }
    return -1;
}