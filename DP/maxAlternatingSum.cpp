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

long long solve(int idx, bool flag, vector<int> &nums, vector<vector<long long>> &dp){
    int n = nums.size();
    if(idx >= n) return 0;

    if(dp[idx][flag] != -1) return dp[idx][flag];
    
    long long skip = solve(idx + 1, flag, nums, dp);
    long long val = nums[idx];
    if(flag == false) val = -1 * val;
    long long take = val + solve(idx + 1, !flag, nums, dp);

    return dp[idx][flag] = max(take, skip);
}

// long long maxAlternatingSum(vector<int>& nums) {
//     int n = nums.size();
//     vector<vector<long long>> dp(n + 1, vector<long long>(2, -1));

//     return solve(0, true, nums, dp);
// }

long long maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));

    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1] - nums[i - 1], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] + nums[i - 1], dp[i - 1][1]);
    }

    return max(dp[n][0], dp[n][1]);
}