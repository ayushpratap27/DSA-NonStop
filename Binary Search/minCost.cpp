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


long long getCost(vector<int> &nums, vector<int> &cost, long long mid) {
    long long sum = 0;
    for(int i = 0; i < nums.size(); i++) {
        sum += (abs(nums[i] - mid) * cost[i]);
    }

    return sum;
}

long long minCost(vector<int>& nums, vector<int>& cost) {
    int n = nums.size();
    long long low = *min_element(nums.begin(), nums.end());
    long long high = *max_element(nums.begin(), nums.end());

    long long result = INT_MAX;

    while(low <= high) {
        long long mid = low + (high - low) / 2;

        long long cost1 = getCost(nums, cost, mid);
        long long cost2 = getCost(nums, cost, mid + 1);

        result = min(cost1, cost2);

        if(cost2 > cost1) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result == INT_MAX ? 0 : result;
}
