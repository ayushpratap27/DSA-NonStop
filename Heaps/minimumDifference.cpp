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


long long minimumDifference(vector<int>& nums) {
    int n3 = nums.size(), n = n3 / 3;
    vector<long long> part1(n + 1);
    long long sum = 0;
    priority_queue<int> pq1;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        pq1.push(nums[i]);
    }
    part1[0] = sum;
    for (int i = n; i < n * 2; i++) {
        sum += nums[i];
        pq1.push(nums[i]);
        sum -= pq1.top();
        pq1.pop();
        part1[i - (n - 1)] = sum;
    }

    long long part2 = 0;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i = n * 3 - 1; i >= n * 2; i--) {
        part2 += nums[i];
        pq2.push(nums[i]);
    }
    long long ans = part1[n] - part2;
    for (int i = n * 2 - 1; i >= n; i--) {
        part2 += nums[i];
        pq2.push(nums[i]);
        part2 -= pq2.top();
        pq2.pop();
        ans = min(ans, part1[i - n] - part2);
    }
    return ans;
}
