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
int dp[1005][250], rowValid[250][250];
vector<int> good, pattern [250];
int colorTheGrid(int m, int n) {
    int total = pow(3, m);

    for (int i = 0; i < total; i++) {
        int val = i, valid = 1;
        for (int j = 0; j < m; j++) 
            pattern[i].push_back(val % 3), val /= 3;
        for (int j = 1; j < m; j++) 
            if (pattern[i][j] == pattern[i][j - 1]) valid = 0;
        if (valid) good.push_back(i);
    }
    
    for (int i : good) dp[1][i] = 1;

    for (int i : good) {
        for (int j : good) {
            rowValid[i][j] = 1;
            for (int k = 0; k < m; k++) 
                if (pattern[i][k] == pattern[j][k]) 
                    rowValid[i][j] = 0;
        }
    }

    for (int col = 2; col <= n; col++)
        for (int i : good)
            for (int j : good)
                if (rowValid[i][j]) 
                    dp[col][i] = (dp[col][i] + dp[col - 1][j]) % mod;
                    
    return accumulate(dp[n], dp[n] + total, 0L) % mod;
}
