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

int maxDistance(string s, int k) {
    int ans = 0, north = 0, south = 0, east = 0, west = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N')
            north++;
        if (s[i] == 'S')
            south++;
        if (s[i] == 'E')
            east++;
        if (s[i] == 'W')
            west++;
        int x = abs(north - south);
        int y = abs(east - west);
        int ini = x + y;
        int dis = ini + min(2 * k, i + 1 - ini);
        ans = max(ans, dis);
    }
    return ans;
}

// int maxDistance(string s, int k) {
//     int ans = 0;
//     int n = s.size();
//     map<char, int> mp;
//     for(int i = 0; i < n; i++) {
//         mp[s[i]]++;
//         int temp = min(i+1,
//         abs(mp['N'] - mp['S']) + abs(mp['E'] - mp['W']) + 2*k);
//         ans = max(ans,temp);
//     }
//     return ans;
// }