#include<bits/stdc++.h>
using namespace std;



int numJewelsInStones(string jewels, string stones) {
    int n=stones.size();
    int m=jewels.size();
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(stones[j]==jewels[i]){
                count++;
            }
        }
    }

    return count;
}

// int numJewelsInStones(string j, string s) {
//         unordered_map<char, int> gems;
//         for(int i=0; i<s.size(); i++){
//             gems[s[i]]++;
//         }
//         int sum=0;
//         for(auto i: gems){
//             if(j.find(i.first) != string::npos) {
//                 sum += i.second;
//             }
//         }
//         return sum;
// }