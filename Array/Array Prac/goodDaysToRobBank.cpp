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

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int n = security.size();
    vector<int> inr(n, 0);
    vector<int> dcr(n, 0);
    vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (security[i] <= security[i - 1]) {
            dcr[i] = dcr[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (security[i] <= security[i + 1]) {
            inr[i] = inr[i + 1] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (inr[i] >= time && dcr[i] >= time) {
            ans.push_back(i);
        }
    }
    return ans;
}