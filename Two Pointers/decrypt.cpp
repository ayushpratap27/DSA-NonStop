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


vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> ans(n, 0);
    if (k == 0)
        return ans;
    if (k > 0) {
        int wsum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
        ans[0] = wsum;
        for (int l = 1, r = k + 1; l < n; r++, l++) {
            wsum += -code[l] + code[r % n];
            ans[l] = wsum;
        }
        return ans;
    }
    k = -k;
    int wsum = accumulate(code.end() - k, code.end(), 0);
    ans[0] = wsum;
    for (int r = 0, l = n - k; r < n - 1; r++, l++) {
        wsum += -code[l % n] + code[r];
        ans[r + 1] = wsum;
    }

    return ans;    
}