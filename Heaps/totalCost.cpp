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

long long totalCost(vector<int>& costs, int k, int candidates) {
    int n = costs.size();
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;

    long long ans = 0;
    int hired = 0;
    int i = 0, j = n - 1;

    while(hired < k){
        while(pq1.size() < candidates && i <= j) {
            pq1.push(costs[i]);
            i++;
        }

        while(pq2.size() < candidates && j >= i) {
            pq2.push(costs[j]);
            j--;
        }

        int min_pq1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
        int min_pq2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

        if(min_pq1 <= min_pq2) {
            ans += min_pq1;
            pq1.pop();
        } else {
            ans += min_pq2;
            pq2.pop();
        }

        hired++;

    }

    return ans;
}