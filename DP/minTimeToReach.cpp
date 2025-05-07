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

int f(int x, int y, vector<vector<int>> & moveTime, vector<vector<int>> &dp, int currT){
    int n = moveTime.size();
    int m = moveTime[0].size();

    if (x == n - 1 && y == m - 1) return currT;
    
    if(currT >= dp[x][y]) return INT_MAX;
    dp[x][y] = currT;

    int minTime = INT_MAX;

    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4;i++) {
        int p = x + delRow[i];
        int q = y + delCol[i];

        if (p >= 0 && p < n && q >= 0 && q < m) {
            int t = max(moveTime[p][q] - currT, 0);
            minTime = min(minTime, f(p, q, moveTime, dp, currT + t + 1));
        }
    }

    return minTime;

}

int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size();
    int m = moveTime[0].size();

    vector<vector<int>> dp(n, vector<int>(m , INT_MAX));
    int ans = f(0, 0, moveTime, dp, 0);
    
    return ans == INT_MAX ? -1 : ans; 
}