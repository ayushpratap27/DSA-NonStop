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


int evenA = 0, oddA = 0, evenB = 0, oddB = 0;

vector<vector<int>> buildList(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    return adj;
}

void bfsColor(vector<vector<int>>& adj, vector<int>& color, bool isA) {
    queue<int> q;
    q.push(0);
    color[0] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (color[u] == 0) {
            if (isA) evenA++;
            else evenB++;
        } else {
            if (isA) oddA++;
            else oddB++;
        }

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            }
        }
    }
}

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    vector<vector<int>> adjA = buildList(edges1);
    vector<vector<int>> adjB = buildList(edges2);
    vector<int> colorA(n, -1), colorB(m, -1);

    evenA = oddA = evenB = oddB = 0;
    bfsColor(adjA, colorA, true);
    bfsColor(adjB, colorB, false);

    int maxiB = max(evenB, oddB);

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (colorA[i] == 0)
            res[i] = evenA + maxiB;
        else
            res[i] = oddA + maxiB;
    }

    return res;
}
