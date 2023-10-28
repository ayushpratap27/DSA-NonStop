#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {
    int n = v.size();
    int candidate = v[0];
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] == candidate) {
            count++;
        } else {
            count--;
        }

        if (count == 0) {
            candidate = v[i];
            count = 1;
        }
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == candidate) {
            count++;
        }
    }

    if (count > n / 2) {
        return candidate;
    } else {
        return -1;
    }
}


int main(){

}