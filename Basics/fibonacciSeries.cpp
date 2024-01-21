#include<bits/stdc++.h>
using namespace std;

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.
    vector<int> fibonacciNumbers;

    if(n<=0){
        return fibonacciNumbers;
    }

    fibonacciNumbers.push_back(0);
    if(n==1){
        return fibonacciNumbers; 
    }
    fibonacciNumbers.push_back(1);
    if(n==2){
        return fibonacciNumbers;
    }
    for(int i=2;i<n;i++){
        int nextFibonacci=fibonacciNumbers[i-1] + fibonacciNumbers[i-2];
        fibonacciNumbers.push_back(nextFibonacci);
    }

    return fibonacciNumbers;
}