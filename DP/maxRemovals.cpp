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


vector<int> vis;
vector<vector<int>> dp;
int f(string& source, string& pattern, int i, int j) {
    if(j == pattern.length()) return 0;
    if(i == source.length()) return INT_MAX;

    if(dp[i][j] != -1) return dp[i][j];

    int perform = f(source, pattern, i+1, j);
    int notPerform = INT_MAX;
    if(source[i] == pattern[j]) {
        int x = 0;
        if(vis[i]) x = 1;

        int y = f(source, pattern, i+1, j+1);
        if(y != INT_MAX)
            notPerform = x + y;
    }
    return dp[i][j] = min(notPerform, perform);
}

int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
    int n = source.size();
    vis.resize(n, 0);
    dp.resize(n, vector<int>(pattern.length(), -1));

    for(auto it: targetIndices) vis[it] = 1;
    int ans = f(source, pattern, 0, 0);

    if(ans == INT_MAX) ans = 0;
    return targetIndices.size() - ans;
}