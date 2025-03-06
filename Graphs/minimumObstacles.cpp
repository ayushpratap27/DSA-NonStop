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

int minimumObstacles(vector<vector<int>> &grid){
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
    deque<pair<int, int>> dq;

    distance[0][0] = 0;
    dq.push_front({0, 0});
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!dq.empty()){
        auto [x, y] = dq.front();
        dq.pop_front();
        for (auto [dx, dy] : directions){
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                int newDist = distance[x][y] + grid[nx][ny];
                if (newDist < distance[nx][ny]){
                    distance[nx][ny] = newDist;
                    if (grid[nx][ny] == 0){
                        dq.push_front({nx, ny});
                    }
                    else{
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
    }

    return distance[m - 1][n - 1];
    
}