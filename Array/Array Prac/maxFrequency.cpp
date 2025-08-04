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

int maxFrequency(vector<int>& nums, int k, int numOperations) {
    unordered_map<int,int>range;
    unordered_map<int,int>freq;

    int minrange = 1e9;
    int maxrange = -1e9;

    for(int i = 0; i < nums.size(); i++){
        freq[nums[i]]++;
        int l = nums[i] - k;
        int r = nums[i] + k;

        minrange = min(minrange, l);
        maxrange = max(maxrange, r);
        range[l]++;
        range[r + 1]--;
    }

    int ans = 1;
    for(int i = minrange; i <= maxrange; i++){
        range[i] += range[i - 1];
        int cnt = freq[i];
        int maxfreq = range[i] - freq[i];
        maxfreq = min(maxfreq, numOperations);
        ans = max(ans, cnt + maxfreq);
    }

    return ans;
}