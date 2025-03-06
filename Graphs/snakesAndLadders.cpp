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

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size(), lbl = 1;
    vector<pair<int, int>> cells(n * n + 1);
    vector<int> columns(n);
    iota(columns.begin(), columns.end(), 0);

    for (int row = n - 1; row >= 0; row--) {
        for (int column : columns) {
            cells[lbl++] = {row, column};
        }
        reverse(columns.begin(), columns.end());
    }

    vector<int> dist(n * n + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
            auto [row, column] = cells[next];
            int destination =
                board[row][column] != -1 ? board[row][column] : next;
            if (dist[destination] == -1) {
                dist[destination] = dist[curr] + 1;
                q.push(destination);
            }
        }
    }
    
    return dist[n * n];
}