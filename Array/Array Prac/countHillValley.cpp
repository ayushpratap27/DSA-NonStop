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

int countHillValley(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;  
    for(int i = 1; i < n - 1; i++) {
        if(nums[i] == nums[i - 1]) continue;
        int left = 0; 
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] > nums[i]){
                left = 1;
                break;
            }else if (nums[j] < nums[i]){
                left = -1;
                break;
            }
        }
        int right = 0; 
        for(int j = i + 1; j < n; j++){
            if(nums[j] > nums[i]) {
                right = 1;
                break;
            }else if (nums[j] < nums[i]) {
                right = -1;
                break;
            }
        }
        if(left == right && left != 0){
            ans++;
        }
    }
    return ans;
}