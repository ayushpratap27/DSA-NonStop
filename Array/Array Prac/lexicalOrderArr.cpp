#include <bits/stdc++.h>
using namespace std;

vector<int> lexicalOrder(int n)
{
    vector<int> v;
    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        v.push_back(curr);
        if (curr * 10 <= n)
        {
            curr *= 10;
        }
        else
        {
            while (curr % 10 == 9 || curr + 1 > n)
            {
                curr /= 10;
            }
            curr++;
        }
    }
    return v;
}