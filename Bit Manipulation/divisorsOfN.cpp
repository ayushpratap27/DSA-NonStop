#include<bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }

    return divisors;
}