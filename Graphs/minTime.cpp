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

int minTime(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, pair<int, int>>>> graph(n);
    for(auto e : edges) {
        int u = e[0], v = e[1], start = e[2], end = e[3];
        graph[u].push_back({v, {start, end}});
    }

    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        auto [time, u] = pq.top(); pq.pop();

        if(u == n - 1) return time;
        if(time > dist[u]) continue;

        for(auto [v, range] : graph[u]) {
            int start = range.first;
            int end = range.second;

            if(time < start) {
                if(start + 1 < dist[v]) {
                    dist[v] = start + 1;
                    pq.push({start + 1, v});
                }
            } else if(time >= start && time <= end) {
                if(time + 1 < dist[v]) {
                    dist[v] = time + 1;
                    pq.push({time + 1, v});
                }
            }
        }

        if(time + 1 < dist[u]){
            dist[u] = time + 1;
            pq.push({time + 1, u});
        }
    }

    return -1;
}