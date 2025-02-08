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

vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    
    for(int i = 0; i < n; i++){
        vector<int> dia;
        int r = i, c = 0;
        while(r < n && c < n){
            dia.push_back(grid[r][c]);
            r++;
            c++;
        }
        sort(dia.rbegin(), dia.rend());
        r = i, c = 0;
        int idx = 0;
        while(r < n && c < n){
            grid[r][c] = dia[idx];
            r++;
            c++;
            idx++;
        }
    }
    
    for(int i = 1; i < n; i++){
        vector<int> dia;
        int r = 0, c = i;
        while(r < n && c < n){
            dia.push_back(grid[r][c]);
            r++;
            c++;
        }
        sort(dia.begin(), dia.end());
        r = 0, c = i;
        int idx = 0;
        while(r < n && c < n){
            grid[r][c] = dia[idx];
            r++;
            c++;
            idx++;
        }
    }
    
    return grid;
}