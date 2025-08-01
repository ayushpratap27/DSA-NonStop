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

int maximumGain(string s, int x, int y) {
    int score = 0;
    char ch1 = 'a', ch2 = 'b';
    int cnt1 = 0, cnt2 = 0;

    if (x < y) {
        swap(x, y);
        ch1 = 'b';
        ch2 = 'a';
    }

    for (char ch : s) {
        if (ch == ch1) {
            cnt1++;
        } else if (ch == ch2) {
            if (cnt1 > 0) {
                cnt1--;
                score += x;
            } else {
                cnt2++;
            }
        } else {
            score += min(cnt1, cnt2) * y;
            cnt1 = 0;
            cnt2 = 0;
        }
    }

    if (cnt1 != 0) {
        score += min(cnt1, cnt2) * y;
    }

    return score;
}