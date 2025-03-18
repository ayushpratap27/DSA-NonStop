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

vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;

    for(int i = 0; i < n; i++){
        mp[nums[i]].push_back(i);
    }

    vector<int> result;
    for(int q : queries){
        int val = nums[q];
        auto& arr = mp[val];

        if(arr.size() == 1){
            result.push_back(-1);
            continue;
        }

        auto it = lower_bound(arr.begin(), arr.end(), q);
        int minDist = INT_MAX;

        if(it != arr.begin()) minDist = min(minDist, q - *prev(it));

        if(next(it) != arr.end()) minDist = min(minDist, *next(it) - q);

        minDist = min(minDist, n - abs(arr.front() - q));
        minDist = min(minDist, n - abs(arr.back() - q));

        result.push_back(minDist);
    }

    return result;
}