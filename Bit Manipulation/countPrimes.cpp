#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }

    // Create a boolean array "isPrime[0..n]" and initialize all entries as true.
    // A value in isPrime[i] will finally be false if i is Not a prime, else true.
    std::vector<bool> isPrime(n, true);

    // Start with the first prime number, 2.
    for (int p = 2; p * p < n; ++p) {
        // If isPrime[p] is not changed, then it is a prime.
        if (isPrime[p]) {
            // Update all multiples of p.
            for (int i = p * p; i < n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Count the number of primes.
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            ++count;
        }
    }

    return count;
}
