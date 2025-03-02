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

int cost(char c1, char c2){
    return min(abs(c1 - c2), 26 - abs(c1 - c2));
}

int longestPalindromicSubsequence(string s, int k) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            dp[i][i][j] = 1;
        }
    }

    for(int l = 2; l <= n; l++){
        for(int i = 0; i <= n - l; i++){
            int j = i + l - 1;
            for(int x = 0; x <= k; x++){
                if(s[i] == s[j]){
                    dp[i][j][x] = 2 + dp[i+1][j-1][x];
                } else {
                    int p = dp[i+1][j][x];
                    int q = dp[i][j-1][x];
                    int c = cost(s[i], s[j]);
                    int r = (x >= c) ? 2 + dp[i+1][j-1][x-c] : 0;
                    dp[i][j][x] = max({p, q, r});
                }
            }
        }
    }

    return dp[0][n-1][k];
}