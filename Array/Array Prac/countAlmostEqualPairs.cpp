#include<bits/stdc++.h>
using namespace std;

void removeZero(string &temp) {
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '0') {
            temp.erase(i, 1);
            i--;
        } else break;
    }
}

bool canMatch(string &s, string &p) {
    int num1 = stoi(s);
    int num2 = stoi(p);
    if (num1 == num2) return true;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j < s.length(); j++) {
            swap(s[i], s[j]);
            num1 = stoi(s);
            num2 = stoi(p); 
            if (num1 == num2) return true;
            swap(s[i], s[j]); 
        }
    }
    for (int i = 0; i < p.length(); i++) {
        for (int j = i + 1; j < p.length(); j++) {
            swap(p[i], p[j]);
            num1 = stoi(s);
            num2 = stoi(p);
            if (num1 == num2) return true;
            swap(p[i], p[j]); 
        }
    }

    return false;
}


int countPairs(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string s = to_string(nums[i]);
            string p = to_string(nums[j]);
            if (canMatch(s, p)) {
                count++;
            }
        }
    }
    return count;
}