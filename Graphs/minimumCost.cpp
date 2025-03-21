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

class DSU {
    vector<int> rank, parent;
public:
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]); // Path compression
    }

    void unionSet(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 == root2) return;

        if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else if (rank[root2] < rank[root1]) {
            parent[root2] = root1;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
};


vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    DSU dsu(n);

    for (auto& edge : edges) {
        dsu.unionSet(edge[0], edge[1]);
    }

    vector<int> compCost(n, INT_MAX);
    for (auto& edge : edges) {
        int root = dsu.find(edge[0]);
        compCost[root] &= edge[2];
    }

    vector<int> res(query.size());
    for (int i = 0; i < query.size(); i++) {
        int root1 = dsu.find(query[i][0]);
        int root2 = dsu.find(query[i][1]);

        res[i] = (root1 != root2) ? -1 : compCost[root1];
    }

    return res;
}