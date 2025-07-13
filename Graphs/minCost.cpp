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
    vector<int> parent, rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0;i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int xp = find(x), yp = find(y);
        if(xp == yp) return false;
        if(rank[xp] < rank[yp]) parent[xp] = yp;
        else if (rank[xp] > rank[yp]) parent[yp] = xp;
        else {
            parent[yp] = xp;
            rank[xp]++;
        }
        return true;
    }
};

static bool compare(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int minCost(int n, vector<vector<int>>& edges, int k) {
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(n);
    vector<int> vec;

    for(auto e : edges) {
        if(dsu.unite(e[0], e[1])) {
            vec.push_back(e[2]);
        }
    }

    int cnt = 1;
    sort(vec.rbegin(), vec.rend());

    while(cnt < k && !vec.empty()) {
        vec.erase(vec.begin());
        cnt++;
    }

    return vec.empty() ? 0 : vec[0];
}