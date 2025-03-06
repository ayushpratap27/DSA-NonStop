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

class DisjointSet{
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }
            
            return parent[node] = findUPar(parent[node]);
        }
        
        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if (rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        
        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] == size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    
};

int Solve(int n, vector<vector<int>> &edge){
    DisjointSet ds(n);
    int cntExtras = 0;
    for (auto it : edge){
        int u = it[0];
        int v = it[1];
        if (ds.findUPar(u) == ds.findUPar(v)){
            cntExtras++;
        }
        else{
            ds.unionBySize(u, v);
        }
    }
    int cntC = 0;
    for (int i = 0; i < n; i++){
        if (ds.parent[i] == i){
            cntC++;
        }
    }
    int ans = cntC - 1;
    if (cntExtras >= ans)
        return ans;

    return -1;
}
