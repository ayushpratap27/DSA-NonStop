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

int solve(int idx, string s, string word, vector<int> &dp) {
    if (idx >= s.size()) return 0;

    if(dp[idx] != -1) return dp[idx];

    int count = 0, tempIdx = idx;
    while (tempIdx + word.size() <= s.size() && s.substr(tempIdx, word.size()) == word) {
        count++;
        tempIdx += word.size();
    }

    return dp[idx] = max(count, solve(idx + 1, s, word, dp));
}

int maxRepeating(string s, string word) {
    int count = 0;
    string repeated = word;
    
    while (s.find(repeated) != string::npos) {
        count++;
        repeated += word;
    }

    return count;
}

int maxRepeating(string s, string word) {
    vector<int> dp(s.size() + 1, -1);
    return solve(0, s, word, dp);
}