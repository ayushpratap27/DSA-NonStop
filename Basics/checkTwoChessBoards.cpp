#include<bits/stdc++.h>
using namespace std;

bool checkTwoChessboards(string coordinate1, string coordinate2) {

    char c1 = coordinate1[0];
    int r1 = coordinate1[1] - '0';
    char c2 = coordinate2[0];
    int r2 = coordinate2[1] - '0';

    bool color1 = ((c1 - 'a') + r1) % 2;
    bool color2 = ((c2 - 'a') + r2) % 2;

    return color1 == color2; 
}