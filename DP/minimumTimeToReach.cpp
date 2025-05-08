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

int minTimeToReach(vector<vector<int>>& moveTime) {
    int n = moveTime.size(), m = moveTime[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
    minh.push({0, 0, 0});    
    moveTime[0][0] = 0;

    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!minh.empty()) {
        auto current = minh.top();
        minh.pop();
        int currTime = current[0];
        int currRow  = current[1];
        int currCol  = current[2];
        if (currTime >= dp[currRow][currCol]) continue;
        if (currRow == n - 1 && currCol == m - 1) return currTime;
        dp[currRow][currCol] = currTime;

        for (auto& direction : directions) {
            int nextRow = currRow + direction[0];
            int nextCol = currCol + direction[1];
            if (nextRow >= 0 && nextRow < n &&
                nextCol >= 0 && nextCol < m &&
                dp[nextRow][nextCol] == INT_MAX) {
                int cost = (currRow + currCol) % 2 + 1; 
                int start = max(moveTime[nextRow][nextCol], currTime);
                int nextTime = start + cost;
                minh.push({nextTime, nextRow, nextCol});
            }
        }
    }
    return -1;
}