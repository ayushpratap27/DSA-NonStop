#include <bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string> &timePoints)
{
    int n = timePoints.size();
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
    {
        v[i] = (int(timePoints[i][0]) - 48) * 600 + (int(timePoints[i][1]) - 48) * 60 +
               (int(timePoints[i][3]) - 48) * 10 + (int(timePoints[i][4]) - 48);
    }

    int ans = INT_MAX;
    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; i++)
    {
        ans = min(ans, v[i + 1] - v[i]);
    }

    ans = min(ans, abs(v[n - 1] - v[0] - 24 * 60));

    return ans;
}