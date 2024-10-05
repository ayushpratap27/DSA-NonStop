#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2){
    int n1 = s1.size();
    int n2 = s2.size();

    if (n1 > n2)
        return false;

    unordered_map<char, int> mp;

    for (int i = 0; i < n1; i++){
        mp[s1[i]]++;
    }

    int l = 0, r = 0;
    int count = n1;

    while (r < n2){
        if (mp[s2[r]] > 0){
            count--;
        }

        mp[s2[r]]--;
        r++;

        if (count == 0)
            return true;

        if (r - l == n1){
            if (mp[s2[l]] >= 0){
                count++;
            }
            mp[s2[l]]++;
            l++;
        }
    }

    return false;

}   
/*
ime Complexity:

    O(n2) where n2 is the length of s2.
    Each character is processed once as the window slides over s2, and operations on the 
    unordered_map (insert, lookup, update) are on average O(1).
    The window slides over s2, and for each window, the character count is updated. This is 
    efficient for most cases.

Space Complexity:

    O(26) (in practice) for English alphabet characters stored in the unordered_map. In the worst 
    case (with arbitrary characters), the space complexity could be O(n1), depending on the number 
    of distinct characters in s1.
*/