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


bool isPossible(vector<int> &time, long long givenTime, int totalTrips) {
    long long trips = 0;
    for(auto it : time) {
        trips += givenTime / it;
    }

    return trips >= totalTrips;
}

long long minimumTime(vector<int>& time, int totalTrips) {
    int n = time.size();
    long long l = 1, r = (long long)*min_element(time.begin(), time.end()) * totalTrips;

    while(l <= r) {
        long long mid = l + (r - l) / 2;

        if(isPossible(time, mid, totalTrips)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

// long long totTrips(vector<long long> &vec) {
//     long long sum = 0;
//     for(int i = 0; i < vec.size(); i++) {
//         sum += vec[i];
//     }

//     return sum;
// }
// long long minimumTime(vector<int>& time, int totalTrips) {
//     int n = time.size();
//     vector<long long> vec(n);
//     long long t = 0;

//     while(totTrips(vec) != totalTrips) {
//         t++;
//         for(int i = 0; i < n; i++) {
//             vec[i] = t / time[i];
//         }
//         totTrips(vec);
//     }

//     return t;
// }
