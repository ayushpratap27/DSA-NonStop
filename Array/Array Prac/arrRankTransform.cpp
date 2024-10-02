#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int> &arr){
    int n = arr.size();
    set<int> st;
    for (int i = 0; i < n; i++){
        st.emplace(arr[i]);
    }

    unordered_map<int, int> mp;
    int rank = 1;
    for (auto &ele : st){
        mp[ele] = rank;
        rank++;
    }

    for (int i = 0; i < n; i++){
        arr[i] = mp[arr[i]];
    }

    return arr;
}