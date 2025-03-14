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


//     This is still giving TLE

//     unordered_map<string, long long> mp;
//     long long solve(int prev, int idx, vector<int> &nums){
//         if(idx >= nums.size()) return 0;

//         string key = to_string(prev) + "_" + to_string(idx);
//         if(mp.find(key) != mp.end()){
//             return mp[key];
//         }

//         long long notTake = solve(prev, idx + 1, nums);
//         long long take = INT_MIN;
//         if(prev == -1 || nums[prev] - prev <= nums[idx] - idx){
//             take = nums[idx] + solve(idx, idx + 1, nums);
//         }

//         return mp[key] = max<long long>(notTake, take);
//     }

//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = *max_element(nums.begin(), nums.end());
//         if(maxi <= 0){
//             return maxi;
//         }
//         return solve(-1, 0, nums);
//     }


// Unfortunately Bottom-Up(tabulation) is also giving TLE
// long long maxBalancedSubsequenceSum(vector<int> &nums) {
//     int n = nums.size();

//     int maxi = *max_element(nums.begin(), nums.end());
//     if(maxi <= 0){
//         return maxi;
//     }

//     vector<long long> dp(n);
//     for(int i = 0; i < n; i++) {
//         dp[i] = nums[i];
//     }

//     long long maxSum = INT_MIN;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < i; j++){
//             if(nums[i] - i >= nums[j] - j){
//                 dp[i] = max<long long>(dp[i], dp[j] + nums[i]);
//                 maxSum = max<long long>(maxSum, dp[i]);
//             }
//         }
//     }

//     return maxSum > maxi ? maxSum : maxi;
// }

long long maxBalancedSubsequenceSum(vector<int> &nums) {
    int n = nums.size();

    map<int, long long> mp; // nums[i] - i, sum

    long long result = INT_MIN;

    for(int i = 0; i < n; i++){
        auto it = mp.upper_bound(nums[i] - i); // it->first = nums[j] - j, it->second = sum
        long long sum = nums[i];
        if(it != mp.begin()){
            it--;
            sum += it->second;
        }

        mp[nums[i] - i] = max(mp[nums[i] - i], sum);

        it = mp.upper_bound(nums[i] - i);

        while(it != mp.end() && it->second <= sum) {
            mp.erase(it++);
        }

        result = max(result, sum);
    }

    return result;
}
