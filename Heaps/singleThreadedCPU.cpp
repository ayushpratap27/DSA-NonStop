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

vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();

    vector<array<int, 3>> vec;

    for(int i = 0; i < n; i++) {
        int startTime = tasks[i][0];
        int duration = tasks[i][1];

        vec.push_back({startTime, duration, i});
    }

    sort(vec.begin(), vec.end());

    vector<int> res;

    long long currTime = 0;
    int idx = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    while(idx < n || !pq.empty()) {
        if(pq.empty() && currTime < vec[idx][0]) {
            currTime = vec[idx][0];
        }

        while(idx < n && vec[idx][0] <= currTime) {
            pq.push({vec[idx][1], vec[idx][2]});
            idx++;
        }

        currTime += pq.top().first;
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}