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

int minimumTime(vector<vector<int>> &grid){
    if (grid[0][1] > 1 && grid[1][0] > 1)
        return -1;

    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        minHeap;

    minHeap.push({0, {0, 0}}); // time, row(x), col(y)

    vector<vector<int>> seen(rows, vector<int>(cols, 0));
    seen[0][0] = 1;

    vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!minHeap.empty()){
        auto curr = minHeap.top();
        int currTime = curr.first;
        int currRow = curr.second.first;
        int currCol = curr.second.second;

        minHeap.pop();

        if (currRow == rows - 1 && currCol == cols - 1)
            return currTime;

        for (auto move : moves){
            int nextRow = move.first + currRow;
            int nextCol = move.second + currCol;

            if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols && !seen[nextRow][nextCol]){

                int waitTime = ((grid[nextRow][nextCol] - currTime) % 2 == 0) ? 1 : 0;
                int nextTime = max(currTime + 1, grid[nextRow][nextCol] + waitTime);

                minHeap.push({nextTime, {nextRow, nextCol}});
                seen[nextRow][nextCol] = 1;
            }
        }
    }
    return -1;
}