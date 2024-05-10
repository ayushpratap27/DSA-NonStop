#include <bits/stdc++.h> 
using namespace std;


bool isBinary(string &bin) {

     for (char c : bin) {
        if (c != '0' && c != '1') {
            return false; 
        }
    }
    return true; 
}