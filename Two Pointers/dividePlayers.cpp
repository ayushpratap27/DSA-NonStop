#include <bits/stdc++.h>
using namespace std;

long long dividePlayers(vector<int> &skill){
    int n = skill.size();
    sort(skill.begin(), skill.end());

    int l = 0, r = n - 1;
    long long totalChemistry = 0;

    int targetSum = skill[l] + skill[r];

    while (l < r){
        if (skill[l] + skill[r] != targetSum){
            return -1;
        }
        totalChemistry += skill[l] * skill[r];
        l++;
        r--;
    }

    return totalChemistry;
} // O(n log n) time complexity
