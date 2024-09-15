#include <bits/stdc++.h>
using namespace std;

vector<int> getSneakyNumbers(vector<int> &nums)
{
    vector<int> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            ans.push_back(nums[i]);
            i++;
        }
    }

    return ans;
}

//      Another Method
vector<int> getSneakyNumbers(vector<int> &nums)
{
    int n = nums.size() - 2;
    vector<int> freq(n, 0);
    vector<int> result;

    for (int num : nums)
    {
        freq[num]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 2)
        {
            result.push_back(i);
            if (result.size() == 2)
                break;
        }
    }

    return result;
}