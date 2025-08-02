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

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int n = landStartTime.size();
    int m = waterStartTime.size();
    long long minTime = LLONG_MAX;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            long long land_finish = (long long)landStartTime[i] + landDuration[i];
            long long water_start = max(land_finish, (long long)waterStartTime[j]);
            long long total_finish = water_start + waterDuration[j];
            minTime = min(minTime, total_finish);
        }
    }

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            long long water_finish = (long long)waterStartTime[j] + waterDuration[j];
            long long land_start = max(water_finish, (long long)landStartTime[i]);
            long long total_finish = land_start + landDuration[i];
            minTime = min(minTime, total_finish);
        }
    }

    return (int)minTime;
}