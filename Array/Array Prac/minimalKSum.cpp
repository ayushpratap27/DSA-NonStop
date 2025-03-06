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

long long sumTotal(long long x, long long y){
    long long sum = (y * (y + 1) / 2) - (x * (x + 1) / 2) - y;

    return sum;
}

long long minimalKSum(vector<int> &nums, int k){
    int n = nums.size();
    sort(nums.begin(), nums.end());

    long long ans = 0;
    if (nums[0] != 1){
        long long eleInBtw = nums[0] - 1;
        if (eleInBtw <= k){
            ans += sumTotal(0, nums[0]);
            k -= eleInBtw;
        }
        else{
            ans += sumTotal(0, 0 + k + 1);
            k = 0;
        }
    }

    for (int i = 1; i < n && k != 0; i++){
        if (nums[i - 1] == nums[i])
            continue;
        long long eleInBtw = nums[i] - nums[i - 1] - 1;
        if (eleInBtw <= k) {
            ans += sumTotal(nums[i - 1], nums[i]);
            k -= eleInBtw;
        }
        else {
            ans += sumTotal(nums[i - 1], nums[i - 1] + k + 1);
            k = 0;
            break;
        }
    }

    if (k != 0) {
        ans += sumTotal(nums[n - 1], nums[n - 1] + k + 1);
    }

    return ans;
}