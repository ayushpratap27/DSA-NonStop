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

vector<int> topoSort(vector<vector<int>>& graph, int k) {
    vector<int> inDegree(k + 1, 0);
    queue<int> q;

    for(int i = 1; i <= k; i++){
        for(int it : graph[i]){
            inDegree[it]++;
        }
    }

    for(int i = 1; i <= k; i++) {
        if(inDegree[i] == 0) q.push(i);
    }

    vector<int> toposort;
    while(!q.empty()){
        int node = q.front(); 
        q.pop();

        toposort.push_back(node);

        for(int adj : graph[node]) {
            inDegree[adj]--;
            if(inDegree[adj] == 0) q.push(adj);
        }
    }

    return toposort.size() == k ? toposort : vector<int>();
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);
    for(auto it : rowConditions) {
        rowGraph[it[0]].push_back(it[1]);
    }

    for(auto it : colConditions) {
        colGraph[it[0]].push_back(it[1]);
    }
    
    vector<int> rowOrder = topoSort(rowGraph, k);
    vector<int> colOrder = topoSort(colGraph, k);
    
    if(rowOrder.empty() || colOrder.empty()) return {};
    
    vector<vector<int>> result(k, vector<int>(k, 0));

    unordered_map<int, int> rowMap;
    unordered_map<int, int> colMap;
    
    for(int i = 0; i < k; i++){
        rowMap[rowOrder[i]] = i;
        colMap[colOrder[i]] = i;
    }
    
    for(int i = 1; i <= k; i++){
        result[rowMap[i]][colMap[i]] = i;
    }
    
    return result;
}