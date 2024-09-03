#include<bits/stdc++.h>
using namespace std;

int getLucky(string s, int k) {
    string temp;
    for (char c : s) {
        temp += to_string(c - 'a' + 1);
    }

    while (k > 0) {
        long long int sum = 0;
            for (char c : temp) {
        sum += c - '0';
            }
    temp = to_string(sum);
        k--;
    }

    return stoi(temp);
}