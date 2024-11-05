#include<iostream>
#include<string>
using namespace std;

int minChanges(string s) {
    int one = 0, zer = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0'){
            zer++;
        }else{
            one++;
        }
    }
    if (s.size() % 2 == 1){
        return min(one, zer);
    }
    int ans = 0, count = 1;
    for (int i = 1; i < s.size(); i++){
        if (s[i] != s[i - 1]){
            if (count % 2 == 1){
                count = 0;
                ans++;
                continue;
            }
            count = 0;
        }
        count++;
    }
    return ans;
}