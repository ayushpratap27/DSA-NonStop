#include<bits/stdc++.h>
using namespace std;

bool isPrefix(string s1, string s2){
      int i = 0;
      int j = 0;
      while(i < s1.size() && j < s2.size()){
          if(s1[i] != s2[i]){
              return false;
          }
          i++;
          j++;
      }
      if(j == s2.size()) return true;

      return false;
  }

  int prefixCount(vector<string>& words, string pref) {
      int n = words.size();
      int count = 0;
      for (int i = 0; i < n; i++) {
          if(isPrefix(words[i],pref)){
              count++;
          }
      }

      return count;
  }
