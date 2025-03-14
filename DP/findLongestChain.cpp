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

int solve(int idx, int prev, vector<vector<int>> &pairs, vector<vector<int>> &dp) {
    int n = pairs.size();
    if(idx >= n) return 0;

    if(prev != -1 && dp[idx][prev] != -1) return dp[idx][prev];

    int skip = solve(idx + 1, prev, pairs, dp);
    int take = 0;
    if(prev == -1 || pairs[prev][1] < pairs[idx][0]){
        take = 1 + solve(idx + 1, idx, pairs, dp);
    }

    if(prev != -1){
        dp[idx][prev] = max(take, skip);
    }

    return max(take, skip);
}

// int findLongestChain(vector<vector<int>>& pairs) {
//     int n = pairs.size();
//     sort(pairs.begin(), pairs.end());
//     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

//     return solve(0, -1, pairs, dp);
// }

// int findLongestChain(vector<vector<int>>& pairs) {
//     int n = pairs.size();
//     int last = INT_MIN;
//     int chain = 0;

//     sort(pairs.begin(), pairs.end(), [](vector<int> const& a, vector<int> const& b){
//         return a[0] < b[0];
//     });

//     for(auto & p : pairs){
//         if(last == INT_MIN || last < p[0]) last = p[1], chain++;
//         else if(last > p[1]) last = p[1];
//     }

//     return chain;
// }

int findLongestChain(vector<vector<int>> &pairs){
    int n = pairs.size();
    sort(pairs.begin(), pairs.end());
    vector<int> dp(n, 1);

    int maxi = 1;
    for(int ind = 0;ind < n; ind++){
        for(int prev = 0; prev < ind; prev++){
            if(pairs[prev][1] < pairs[ind][0]){
                dp[ind] = max(1 + dp[prev], dp[ind]);
                maxi = max(maxi, dp[ind]);
            }
        }
    }

    return maxi;
}