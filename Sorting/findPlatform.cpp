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

int findPlatform(vector<int> &arr, vector<int> &dep){
    // Your code here
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0, j = 0;
    int count = 0;
    int maxCount = 0;
    while (i < arr.size())
    {   // O(2n) because sometimese it is inc.
        // i and sometimes it is inc. j
        if (arr[i] <= dep[j]) {
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        maxCount = max(maxCount, count);
    }

    return maxCount;
}
// T.C. - O(2nlogn) + O(2n)
// S.C. - O(1)

int findPlatform(vector<int> &arr, vector<int> &dep){
    // Sort both arrival and departure arrays
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int n = arr.size();
    int platforms = 1; // Minimum one platform needed
    int result = 1;    // Track maximum platforms needed at any time

    int i = 1; // Pointer for arrivals
    int j = 0; // Pointer for departures

    while (i < n && j < n) {
        // A train is arriving before the current departure
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        }
        // A train has departed
        else{
            platforms--;
            j++;
        }
        // Update the result with the maximum platforms needed so far
        result = max(result, platforms);
    }

    return result;
}

// T.C. - O(2nlogn) + O(2n)
// S.C. - O(1)