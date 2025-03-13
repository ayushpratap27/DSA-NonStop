#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define ll int64_t
using namespace std;

bool check(string s1, string s2){
    if(s1.size() != s2.size() - 1) return false;

    int i = 0;
    int j = 0;
    while(i < s1.size() && j < s2.size()){
        if(s1[i] == s2[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }

    return i == s1.size();
}

static bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int solve(vector<string> &words, int prev, int curr, vector<vector<int>> &dp){
    int n = words.size();
    if(curr >= n) return 0;

    if(prev != -1 && dp[prev][curr] != -1) return dp[prev][curr];

    int notTake = solve(words, prev, curr + 1, dp);
    int take = 0;
    if(prev == -1 || check(words[prev], words[curr])){
        take = 1 + solve(words, curr, curr + 1, dp); 
    } 

    if(prev != -1){
        dp[prev][curr] = max(take, notTake);
    }

    return max(take, notTake);
}

int longestStrChain(vector<string>& words) {
    int n = words.size();
    sort(words.begin(), words.end(), comp);
    //vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<int> dp(n, 1);

    int maxi = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(1 + dp[j] > dp[i] && check(words[j], words[i])){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}