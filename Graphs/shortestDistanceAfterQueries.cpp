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

int bfs(int start, int end, int n, const vector<vector<int>> &graph){
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (int u : graph[curr]){
            if (dist[u] > dist[curr] + 1){
                dist[u] = dist[curr] + 1;
                q.push(u);
            }
        }
    }

    return dist[end];
}
vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries){
    vector<int> answer;
    vector<vector<int>> graph(n);

    for (int i = 0; i < n - 1; i++){
        graph[i].push_back(i + 1);
    }

    for (auto query : queries){
        int u = query[0], v = query[1];
        graph[u].push_back(v);
        answer.push_back(bfs(0, n - 1, n, graph));
    }

    return answer;
}