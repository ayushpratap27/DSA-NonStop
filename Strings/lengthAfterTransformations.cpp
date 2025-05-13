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

int MOD = 1000000007;

int lengthAfterTransformations(string s, int t) {
    vector<int> cnt(26, 0);

    for (char c : s) {
        cnt[c - 'a']++;
    }

    for(int j = 0; j < t; j++) {
        vector<int> tmp(26, 0);
        for(int i = 0; i < 26; i++) {
            if (i == 25) {
                tmp[0] = (tmp[0] + cnt[i]) % MOD;
                tmp[1] = (tmp[1] + cnt[i]) % MOD;
            } else {
                tmp[i + 1] = (tmp[i + 1] + cnt[i]) % MOD;
            }
        }
        cnt = tmp;
    }

    int len = 0;
    for (int c : cnt) {
        len = (len + c) % MOD;
    }

    return len;
}