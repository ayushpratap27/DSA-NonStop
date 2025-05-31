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

bool fillBobPath(int node, int parent, vector<int>& path, vector<vector<int>>& graph) {
    if (node == 0) return true;
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            path.push_back(node);
            if (fillBobPath(neighbor, node, path, graph)) return true;
            path.pop_back();
        }
    }
    return false;
}

int getAliceMaxScore(int node, int parent, int currScore, vector<int>& bobPath, vector<vector<int>>& graph, int timestamp, vector<int>& amount) {
    if (bobPath[node] == -1 || bobPath[node] > timestamp) {
        currScore += amount[node];
    } else if (bobPath[node] == timestamp) {
        currScore += amount[node] / 2;
    }

    if (graph[node].size() == 1 && node != 0) return currScore;
    int maxScore = INT_MIN;
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            maxScore = max(maxScore, getAliceMaxScore(neighbor, node, currScore, bobPath, graph, timestamp + 1, amount));
        }
    }
    return maxScore;
}

int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = amount.size();
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<int> bobPath(n, -1);
    vector<int> path;
    fillBobPath(bob, -1, path, graph);
    for (int i = 0; i < path.size(); i++) {
        bobPath[path[i]] = i;
    }

    return getAliceMaxScore(0, -1, 0, bobPath, graph, 0, amount);
}