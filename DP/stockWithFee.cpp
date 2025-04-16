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

int solve(int i, int canBuy, vector<int> &prices, vector<vector<int>> &dp, int fee) {
    int n = prices.size();
    if(i >= n) return 0;

    if(dp[i][canBuy] != -1) return dp[i][canBuy];

    int profit = 0;
    if(canBuy) {
        profit = max(-prices[i] + solve(i + 1, 0, prices, dp, fee), solve(i + 1, 1, prices, dp, fee));
    } else {
        profit = max(prices[i] - fee + solve(i + 1, 1, prices, dp, fee), solve(i + 1, 0, prices, dp, fee));
    }

    return dp[i][canBuy] = profit;
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, 1, prices, dp, fee);
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for(int i = n - 1; i >= 0; i--) {
        for(int canBuy = 1; canBuy >= 0; canBuy--) {
            int profit = 0;
            if(canBuy) {
                profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            } else {
                profit = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
            }

            dp[i][canBuy] = profit;
        }
    }

    return dp[0][1];
}