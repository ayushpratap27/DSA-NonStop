#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string str1, string str2) {
    // Check if the lengths of the two strings are equal
    if (str1.length() != str2.length()) {
        return false;
    }

    // Sort the characters in both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare the sorted strings
    return str1 == str2;
}
