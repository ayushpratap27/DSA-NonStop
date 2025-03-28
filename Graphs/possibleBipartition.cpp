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

bool isPossible(int node, vector<int> adj[], vector<int> &color) {
    color[node] = 0;
    queue<int> q;
    q.push(node);

    while(!q.empty()) {
        int newNode = q.front();
        q.pop();

        for(auto it : adj[newNode]) {
            if(color[it] == -1) {
                color[it] = !color[newNode];
                q.push(it);
            } else if (color[it] == color[newNode]) {
                return false;
            }
        }
    }

    return true;
}

bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<int> adj[n+1];
    for(int i = 0; i < dislikes.size(); i++) {
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
        adj[dislikes[i][1]].push_back(dislikes[i][0]);
    }
    
    vector<int> color(n+1, -1);

    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            if(!isPossible(i, adj, color)){
                return false;
            }
        }
    }

    return true;

}