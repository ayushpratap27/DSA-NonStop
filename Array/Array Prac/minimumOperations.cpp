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

//       Brute Force Solution

int minOperations(vector<int>& nums) {
    int cnt = 0;
    int n = nums.size();
    
    while(true) {
        vector<pair<int, int>> subarr;
        int start = -1;
        
        for(int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                if(start == -1) {
                    start = i;
                }
            } else {
                if(start != -1) {
                    subarr.emplace_back(start, i - 1);
                    start = -1;
                }
            }
        }
        
        if(start != -1) {
            subarr.emplace_back(start, n - 1);
        }
        
        if(subarr.empty()) {
            break;
        }
        
        for(auto it : subarr) {
            int min_val = INT_MAX;
            for(int i = it.first; i <= it.second; i++){
                if(nums[i] != 0 && nums[i] < min_val) {
                    min_val = nums[i];
                }
            }
            
            for(int i = it.first; i <= it.second; i++) {
                if(nums[i] == min_val) {
                    nums[i] = 0;
                }
            }
            
            cnt++;
        }
    }
    
    return cnt;
}