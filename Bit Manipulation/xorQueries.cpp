#include<bits/stdc++.h>
using namespace std;

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    vector<int> tempXOR(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        tempXOR[i + 1] = tempXOR[i] ^ arr[i];
    }
    vector<int> ans;
    for (auto &query : queries)
    {
        int left = query[0], right = query[1];
        ans.push_back(tempXOR[right + 1] ^ tempXOR[left]);
    }

    return ans;
}