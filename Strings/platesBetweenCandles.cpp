#include <bits/stdc++.h>
using namespace std;

vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries)
{
    // int n = q.size();
    // int m = q[0].size();
    // int t = s.size();
    // vector<int> v;

    // int ind = 0;
    // while(ind < n){
    //     int x = q[ind][0];
    //     int y = q[ind][1];
    //     int p = 0;
    //     int r = 0;
    //     while(s[x] != '|'){
    //         if(s[x] == '|'){
    //             break;
    //         }else{
    //             x++;
    //         }
    //     }
    //     while(s[y] != '|'){
    //         if(s[y] == '|'){
    //             break;
    //         }else{
    //             y--;
    //         }
    //     }

    //     int cnt = 0;
    //     for(int i=x;i<=y;i++){
    //         if(s[i] == '*'){
    //             cnt++;
    //         }
    //     }
    //     v.push_back(cnt);
    //     ind++;

    // }

    // return v;

    int n = s.size();

    vector<int> prefixPlates(n, 0);
    vector<int> leftCandle(n, -1);
    vector<int> rightCandle(n, -1);

    int plateCount = 0;
    int lastCandle = -1;
    for (int i = 0; i < n; i++){
        if (s[i] == '*'){
            plateCount++;
        }
        prefixPlates[i] = plateCount;

        if (s[i] == '|'){
            lastCandle = i;
        }
        leftCandle[i] = lastCandle;
    }

    lastCandle = -1;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] == '|'){
            lastCandle = i;
        }

        rightCandle[i] = lastCandle;
    }

    vector<int> result;
    for (auto &q : queries){
        int x = q[0];
        int y = q[1];

        int rightBound = rightCandle[x];
        int leftBound = leftCandle[y];

        if (leftBound != -1 && rightBound != -1 && rightBound <= leftBound){
            result.push_back(prefixPlates[leftBound] - prefixPlates[rightBound]);
        }
        else{
            result.push_back(0);
        }
    }

    return result;
}
/*
Time Complexity:

    Preprocessing:
        Calculating the prefixPlates, leftCandle, and rightCandle arrays requires a single 
        traversal of the string s, which is O(n), where n is the length of the string.
    Query Processing:
        Each query is handled in O(1) time since we are just accessing precomputed arrays and 
        performing simple arithmetic.
    Total Time Complexity:
        O(n+q), where n is the length of the string and q is the number of queries. 
        This is much faster than the original O(n×q) approach.
 */