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

long long maximumSubarraySum(vector<int> &nums, int k){
    int n = nums.size();
    unordered_set<int> elements;
    long long current_sum = 0;
    long long max_sum = 0;
    int begin = 0;

    for (int end = 0; end < n; end++){
        if (elements.find(nums[end]) == elements.end()){
            current_sum += nums[end];
            elements.insert(nums[end]);

            if (end - begin + 1 == k){
                max_sum = max(max_sum, current_sum);
                current_sum -= nums[begin];
                elements.erase(nums[begin]);
                begin++;
            }
        }
        else{
            while (nums[begin] != nums[end]){
                current_sum -= nums[begin];
                elements.erase(nums[begin]);
                begin++;
            }
            begin++;
        }
    }

    return max_sum;
}