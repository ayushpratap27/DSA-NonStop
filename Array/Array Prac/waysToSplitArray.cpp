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

int waysToSplitArray(vector<int> &nums) {
    // Keep track of sum of elements on left and right sides
    long long leftSum = 0, rightSum = 0;

    // Initially all elements are on right side
    for (int num : nums) {
        rightSum += num;
    }

    int count = 0;
    // Try each possible split position
    for (int i = 0; i < nums.size() - 1; i++) {
        // Move current element from right to left side
        leftSum += nums[i];
        rightSum -= nums[i];

        // Check if this creates a valid split
        if (leftSum >= rightSum) {
            count++;
        }
    }

    return count;
}

// int waysToSplitArray(vector<int>& nums) {
//     int n = nums.size();
//     vector<long long> prefixSum(n + 1, 0);
//     for (int i = 0; i < n; i++) {
//         prefixSum[i + 1] = prefixSum[i] + nums[i];
//     }

//     int cnt = 0;
//     for (int i = 0; i < n - 1; i++) {
//         long long leftSum = prefixSum[i + 1];
//         long long rightSum = prefixSum[n] - leftSum;

//         if (leftSum >= rightSum) {
//             cnt++;
//         }
//     }

//     return cnt;
// }