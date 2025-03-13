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

int solve(int idx, int prev, vector<int> &nums, vector<vector<int>> &dp){
    int n = nums.size();
    if(idx >= n) return 0;

    if(prev != -1 && dp[idx][prev] != -1) return dp[idx][prev];

    int notTake = solve(idx + 1, prev, nums, dp);
    int take = 0;
    if(prev == -1 || nums[prev] < nums[idx]){
        take = 1 + solve(idx + 1, idx, nums, dp);
    }

    if(prev != -1){
        dp[idx][prev] = max(take, notTake);
    }

    return max(take, notTake);
}

// int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();
//     vector<vector<int>> dp(n + 1,vector<int>(n + 1, -1));
//     return solve(0, -1, nums, dp);
// }

// int lengthOfLIS(vector<int>& nums){
//     int n = nums.size();
//     vector<int> dp(n, 1);

//     int maxi = 1;
//     for(int ind = 0;ind < n; ind++){
//         for(int prev = 0; prev < ind; prev++){
//             if(nums[prev] < nums[ind]){
//                 dp[ind] = max(1 + dp[prev], dp[ind]);
//             }
//         }

//         maxi = max(dp[ind], maxi);
//     }

//     return maxi;
// }

int lengthOfLIS(vector<int> &nums){
    int n = nums.size();

    vector<int> sorted;

    for(int i = 0; i < n; i++){
        auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);

        if(it == sorted.end()){
            sorted.push_back(nums[i]);
        } else {
            *it = nums[i];
        }
    }

    return sorted.size();
}