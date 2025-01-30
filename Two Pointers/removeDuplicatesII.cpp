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

// int removeDuplicates(vector<int>& nums) {
//     int n = nums.size();
//     map<int, int> mp;
//     for (int i = 0; i < n; i++) {
//         mp[nums[i]]++;
//     }

//     int j = 1;
//     for (int i = 1; i < n;i++) {
//         if (nums[i] != nums[i - 1]) {
//             nums[j] = nums[i];
//             j++;
//         } else if (nums[i] == nums[i - 1] && mp[nums[i]] <= 2) {
//             nums[j] = nums[i];
//             j++;
//         } else if (nums[i] == nums[i - 1] && mp[nums[i]] > 2) {
//             mp[nums[i]]--;
//         }
//     }

//     return j;
// }

int removeDuplicates(vector<int>& nums) {
    int k = 2;

    if (nums.size() <= 2) return nums.size();
        
    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;       
}