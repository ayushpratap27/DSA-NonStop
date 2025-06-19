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


long long getSum(long long count, long long x) {
    return (count * x) - (count * (count + 1) / 2);
}

int maxValue(int n, int index, int maxSum) {
    long long low = 1;
    long long high = maxSum;

    int result = 0;
    while(low <= high) {
        long long mid = low + (high - low) / 2;

        long long leftCount = min((long long)index, mid - 1);
        long long leftSum = getSum(leftCount, mid);
        leftSum += max(0LL, index - (mid - 1)); // extra once if any

        long long rightCount = min((long long)(n - index - 1), mid - 1);
        long long rightSum = getSum(rightCount, mid);
        rightSum += max(0LL, (n - index - 1) - (mid - 1));

        long long totalSum = leftSum + mid + rightSum;

        if(totalSum <= maxSum) {
            result = max((long long)result, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}