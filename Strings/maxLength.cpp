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

int &getMin(int &a, int &b, int &c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;

    return c;
}

int maximumLength(string s) {
    int n = s.size();
    vector<vector<int>> top3freq(26, vector<int>(3, -1));
    char last_seen = '*';
    int win_len = 0;

    for (char &curr : s) {
        int idx = curr - 'a';
        win_len = curr == last_seen ? win_len + 1 : 1;
        last_seen = curr;
        int &minimum = getMin(top3freq[idx][0], top3freq[idx][1], top3freq[idx][2]);
        if (win_len > minimum) {
            minimum = win_len;
        }
    }

    int maxLen = -1;
    for (int i = 0; i < 26; i++) {
        maxLen = max(maxLen, min({top3freq[i][0], top3freq[i][1], top3freq[i][2]}));
    }

    return maxLen;
}