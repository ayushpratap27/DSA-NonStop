#include<bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input) {
    int n=input.length();
    int maxLength = 0;
    unordered_set<char> uniqueChars;
    int left = 0; 

    for(int right=0;right<n;right++){
        char currentChar=input[right];

        while(uniqueChars.find(currentChar) != uniqueChars.end()){
            uniqueChars.erase(input[left]);
            left++;
        }

        uniqueChars.insert(currentChar);
        maxLength = max(maxLength, right-left+1);
    }

    return maxLength;
}
