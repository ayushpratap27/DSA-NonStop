#include <bits/stdc++.h>
using namespace std;

bool equalFrequency(string word)
{
    int n = word.size();
    vector<int> freq(26, 0);

    for (int i = 0; i < n; i++)
    {
        freq[word[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            freq[i]--;

            unordered_map<int, int> freqCount;

            for (int j = 0; j < 26; j++)
            {
                if (freq[j] > 0)
                {
                    freqCount[freq[j]]++;
                }
            }

            if (freqCount.size() == 1)
            {
                return true;
            }

            freq[i]++;
        }
    }

    return false;
}