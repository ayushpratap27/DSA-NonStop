#include <bits/stdc++.h>
using namespace std;

vector<int> targetIndices(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> v;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == target)
        {
            v.push_back(i);
        }
    }

    return v;
}
// time complexity O(n log n) due to sorting
// space complexity O(n) for storing the indices
// we can also solve this problem in O(n) time complexity by using counting sort or bucket sort

vector<int> targetIndices(vector<int> &nums, int target)
{
    int countLess = 0;
    int countTarget = 0;

    for (int num : nums){
        if (num < target){
            countLess++;
        }
        else if (num == target){
            countTarget++;
        }
    }

    if (countTarget == 0){
        return {};
    }

    vector<int> result;
    for (int i = 0; i < countTarget; i++){
        result.push_back(countLess + i);
    }

    return result;
}
// time complexity O(n)
// space complexity O(n) for storing the indices

