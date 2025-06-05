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

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& group) {
    visited[node] = true;
    group.push_back(node);
    for (int nei : adj[node]) {
        if (!visited[nei]) {
            dfs(nei, adj, visited, group);
        }
    }
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<vector<int>> adj(26);  

    for (int i = 0; i < s1.size(); i++) {
        int u = s1[i] - 'a';
        int v = s2[i] - 'a';
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(26, false);
    vector<char> rep(26); 

    for (int i = 0; i < 26; i++) {
        if (!visited[i]) {
            vector<int> group;
            dfs(i, adj, visited, group);

            char minChar = 'z';
            for (int idx : group) {
                minChar = min(minChar, (char)(idx + 'a'));
            }

            for (int idx : group) {
                rep[idx] = minChar;
            }
        }
    }

    string res = "";
    for (char ch : baseStr) {
        res += rep[ch - 'a'] == 0 ? ch : rep[ch - 'a'];
    }
    return res;
}