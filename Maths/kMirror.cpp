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


long long createPalindrome(long long num, bool odd) {
    long long x = num;
    if (odd) x /= 10;
    while (x > 0) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return num;
}

bool isPalindrome(long long num, int base) {
    vector<int> digits;
    while (num > 0) {
        digits.push_back(num % base);
        num /= base;
    }
    int i = 0, j = digits.size() - 1;
    while (i < j) {
        if (digits[i++] != digits[j--]) return false;
    }
    return true;
}

long long kMirror(int k, int n) {
    long long sum = 0;
    for (long long len = 1; n > 0; len *= 10) {
        for (long long i = len; n > 0 && i < len * 10; i++) {
            long long p = createPalindrome(i, true);
            if (isPalindrome(p, k)) {
                sum += p;
                n--;
            }
        }
        for (long long i = len; n > 0 && i < len * 10; i++) {
            long long p = createPalindrome(i, false);
            if (isPalindrome(p, k)) {
                sum += p;
                n--;
            }
        }
    }
    return sum;
}
