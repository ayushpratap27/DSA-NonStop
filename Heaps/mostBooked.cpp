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

int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    vector<long long> cnt(n, 0), avail(n, 0);

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;

    priority_queue<int, vector<int>, greater<>> free;
    for(int i = 0;i < n; i++) free.push(i);

    for(auto m : meetings) {
        long long start = m[0], end = m[1];\
        while(!busy.empty() && busy.top().first <= start) {
            free.push(busy.top().second);
            busy.pop();
        }
        if(!free.empty()) {
            int room = free.top(); free.pop();
            busy.push({end, room});
            cnt[room]++;
        } else {
            auto [nextFree, room] = busy.top(); busy.pop();
            busy.push({nextFree + (end - start), room});
            cnt[room]++;
        }
    }
    int res = 0;
    for(int i = 1;i < n; i++) if(cnt[i] > cnt[res]) res = i;

    return res;
}