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


const static int M = 1e9 + 7;
int n, cnt[10], left_s[10], left_c[10], cb[81][81];
long dp[10][361][41], r1[11];

long dfs(int i, int s, int c) {
    if (s == 0 && c == 0)
        return r1[i];
    if (i == 10)
        return 0;
    if (s > left_s[i] || c > left_c[i])
        return 0;
    if (dp[i][s][c] != -1)
        return dp[i][s][c];

    long res = 0;
    int a = s;

    for (int x = 0, y = cnt[i]; x <= cnt[i] && a >= 0 && c >= x; x++, y--, a -= i) {
        if (y > left_c[i] - c)
            continue;
        long b = (dfs(i + 1, a, c - x) * cb[c][x]) % M;
        res = (res + b * cb[left_c[i] - c][y]) % M;
    }

    return dp[i][s][c] = res;
}

void pascal() {
    memset(cb, 0, sizeof(cb));
    cb[0][0] = 1;
    for (int i = 1; i <= 80; i++) {
        cb[i][0] = 1;
        cb[i][i] = 1;
        for (int j = 1; j < i; j++)
            cb[i][j] = (cb[i - 1][j - 1] + cb[i - 1][j]) % M;
    }
}


int countBalancedPermutations(string num) {
    int s = 0, ls = 0, lc = 0;
    memset(cnt, 0, sizeof(cnt));
    for (char c : num) {
        s += (c - '0');
        cnt[c - '0']++;
    }

    if (s & 1) return 0;

    pascal();

    r1[10] = 1;
    for (int i = 9; i > -1; i--) {
        ls += i * cnt[i];
        lc += cnt[i];
        left_s[i] = ls;
        left_c[i] = lc;
        r1[i] = (r1[i + 1] * cb[left_c[i]][cnt[i]]) % M;
    }

    n = int(num.size());
    memset(dp, -1, sizeof(dp));
    
    return dfs(0, s >> 1, n >> 1);
}
