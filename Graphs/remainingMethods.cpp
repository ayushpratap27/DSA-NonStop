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

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    vector<vector<int>> adj(n);
    for(auto it : invocations) {
        adj[it[0]].push_back(it[1]);
    }

    vector<int> vis(n, 0);
    dfs(k, adj, vis);

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            for(auto it : adj[i]) {
                if(vis[it]) {
                    flag = true;
                    break;
                }
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(vis[i]) {
            if(flag) ans.push_back(i);
        } else {
            ans.push_back(i);
        }
    }

    return ans;
}

