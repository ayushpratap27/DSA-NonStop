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

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool isValid(int adjr, int adjc, int n, int m){
	return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	DisjointSet ds(n*m);
	int vis[n][m];
	memset(vis, 0, sizeof vis);
	int cnt = 0;
	vector<int> ans;
	for(auto it : q){
		int row = it[0];
		int col = it[1];
		if(vis[row][col] == 1){
			ans.push_back(cnt);
			continue;
		}
		vis[row][col] = 1;
		cnt++;
		int dr[] = {-1, 0, 1, 0};
		int dc[] = {0, 1, 0, -1};
		for(int ind = 0;ind < 4; ind++){
			int adjr = row + dr[ind];
			int adjc = col + dc[ind];

			if(isValid(adjr, adjc, n, m)){
				if(vis[adjr][adjc] == 1){
					int nodeNo = row*m + col;
					int adjNodeNo = adjr*m + adjc;
					if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
						cnt--;
						ds.unionBySize(nodeNo, adjNodeNo);
					}
				}
			}
		}
		ans.push_back(cnt);
	}

	return ans;
}