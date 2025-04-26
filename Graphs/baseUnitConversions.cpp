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


int MOD = 1e9 + 7;
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int maxi = 0;
        for(auto it : conversions) {
            maxi = max(maxi, max(it[0], it[1]));
        }
        
        int n = maxi + 1; 
        
        vector<vector<pair<int, int>>> graph(n);
        for(auto it : conversions) {
            int u = it[0], v = it[1], w = it[2];
            graph[u].emplace_back(v, w);
        }
        
        vector<int> res(n, 0);
        res[0] = 1;
        
        queue<pair<int, long long>> q;
        q.push({0, 1});
        
        while(!q.empty()){
            auto [u, factor_u] = q.front();
            q.pop();
            
            for(auto [v, w] : graph[u]) {
                if(res[v] == 0) {
                    long long new_factor = (factor_u * w) % MOD;
                    res[v] = new_factor;
                    q.push({v, new_factor});
                }
            }
        }
        
        return res;
    }
};