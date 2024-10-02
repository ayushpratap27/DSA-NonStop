#include <bits/stdc++.h>
using namespace std;

long long sumBetweenTwoKth(long long A[], long long n, long long K1, long long K2){

    priority_queue<long long> p1, p2;

    for (long long i = 0; i < K1; i++){
        p1.push(A[i]);
    }

    for (long long i = K1; i < n; i++){
        if (A[i] < p1.top()){
            p1.pop();
            p1.push(A[i]);
        }
    }

    for (long long i = 0; i < K2 - 1; i++){
        p2.push(A[i]);
    }

    for (long long i = K2 - 1; i < n; i++){
        if (A[i] < p2.top()){
            p2.pop();
            p2.push(A[i]);
        }
    }

    long long sum1 = 0, sum2 = 0;
    while (!p1.empty()){
        sum1 += p1.top();
        p1.pop();
    }

    while (!p2.empty()){
        sum2 += p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}