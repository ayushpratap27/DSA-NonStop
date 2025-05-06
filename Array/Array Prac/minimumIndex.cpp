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

int minimumIndex(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int num = 0, count = 0;

    for(int it : nums) {
        mp[it]++;
    }

    for(auto& it : mp) {
        if(it.second > n / 2) {
            num = it.first;
            count = it.second;
            break;
        }
    }

    int leftCount = 0;
    for(int i = 0; i < n - 1; i++) {
        if (nums[i] == num) leftCount++;
        int leftSize = i + 1;
        int rightSize = n - leftSize;
        int rightCount = count - leftCount;

        if (leftCount > leftSize / 2 && rightCount > rightSize / 2) {
            return i;
        }
    }

    return -1;
}