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


const int mod = 1e9 + 7;

int possibleStringCount(string word, int k) {
    int n = word.size();
    int currentCount = 1;
    vector<int> groupSizes;

    for (int i = 1; i < n; ++i) {
        if (word[i] == word[i - 1]) {
            currentCount++;
        } else {
            groupSizes.push_back(currentCount);
            currentCount = 1;
        }
    }
    groupSizes.push_back(currentCount);

    long long totalWays = 1;
    for (int size : groupSizes) {
        totalWays = (totalWays * size) % mod;
    }

    if ((int)groupSizes.size() >= k) {
        return totalWays;
    }

    vector<int> dp(k, 0);
    vector<int> prefixSum(k, 1);
    dp[0] = 1;

    for (int i = 0; i < groupSizes.size(); ++i) {
        int groupSize = groupSizes[i];
        vector<int> newDp(k, 0);

        for (int j = 1; j < k; ++j) {
            newDp[j] = prefixSum[j - 1];
            if (j - groupSize - 1 >= 0) {
                newDp[j] = (newDp[j] - prefixSum[j - groupSize - 1] + mod) % mod;
            }
        }

        vector<int> newPrefix(k, 0);
        newPrefix[0] = newDp[0];
        for (int j = 1; j < k; ++j) {
            newPrefix[j] = (newPrefix[j - 1] + newDp[j]) % mod;
        }

        dp = newDp;
        prefixSum = newPrefix;
    }

    return (totalWays - prefixSum[k - 1] + mod) % mod;
}