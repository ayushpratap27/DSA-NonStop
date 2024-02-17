#include <bits/stdc++.h> 
using namespace std;


bool isVowel(char ch) {
    ch = tolower(ch); 
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

bool splitString(string& str) {
    int length = str.length();

    if (length % 2 != 0) {
        return false;
    }

    int vowelsFirstHalf = 0;
    for (int i = 0; i < length / 2; i++) {
        if (isVowel(str[i])) {
            vowelsFirstHalf++;
        }
    }

    int vowelsSecondHalf = 0;
    for (int i = length / 2; i < length; i++) {
        if (isVowel(str[i])) {
            vowelsSecondHalf++;
        }
    }

    return (vowelsFirstHalf == vowelsSecondHalf);
}