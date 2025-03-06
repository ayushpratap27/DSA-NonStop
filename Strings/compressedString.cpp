#include<iostream>
#include<string>
using namespace std;

string compressedString(string word) {
    int n = word.size();
    int cnt = 1;
    string ans = "";
    char ch = word[0];
    for (int i = 1; i < n; i++)
    {
        if (word[i] == ch && cnt < 9)
        {
            cnt++;
        }
        else
        {
            ans.push_back(cnt + '0');
            ans.push_back(ch);
            ch = word[i];
            cnt = 1;
        }
    }
    ans.push_back(cnt + '0');
    ans.push_back(ch);

    return ans;
}