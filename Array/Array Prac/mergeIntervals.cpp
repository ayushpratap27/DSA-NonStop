#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
        return {};
    }

    // Sort intervals based on the start time
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });

    vector<vector<int>> mergedIntervals;
    mergedIntervals.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (mergedIntervals.back()[1] >= intervals[i][0]) {
            // If the current interval overlaps with the previous one, merge them
            mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
        } else {
            // If there is no overlap, add the current interval to the result
            mergedIntervals.push_back(intervals[i]);
        }
    }

    return mergedIntervals;
}
