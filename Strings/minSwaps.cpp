#include <bits/stdc++.h>
using namespace std;

int minSwaps(string s){
    int size = 0;
    int n = s.size();
    for (int i = 0; i < n; i++){
        char ch = s[i];
        if (ch == '[')
            size++;
        else if (size > 0)
            size--;
    }

    return (size + 1) / 2;
    
}
// Time Complexity - O(n)
// Space Complexity - O(1)

