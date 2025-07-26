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

long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    vector<vector<int>> right(n + 1);
    for (const auto& pair : conflictingPairs) {
        right[max(pair[0], pair[1])].push_back(min(pair[0], pair[1]));
    }

    long long ans = 0;
    vector<long long> left = {0, 0};
    vector<long long> bonus(n + 1, 0);

    for (int r = 1; r <= n; r++) {
        for (int l_val : right[r]) {
            if (l_val > left[0]) {
                left = {static_cast<long long>(l_val), left[0]};
            } else if (l_val > left[1]) {
                left = {left[0], static_cast<long long>(l_val)};
            }
        }

        ans += r - left[0];
        
        if (left[0] > 0) {
            bonus[left[0]] += left[0] - left[1];
        }
    }
    
    long long max_bonus = 0;
    for(long long b : bonus) {
        max_bonus = max(max_bonus, b);
    }

    return ans + max_bonus;
}