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

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    
    if(x <= arr[0]){
        return vector<int>(arr.begin(), arr.begin() + k);
    }
    if(x >= arr[n - 1]){
        return vector<int>(arr.end() - k, arr.end());
    }

    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(arr[mid] < x){
            l = mid + 1;
        }else{
            r = mid;
        }
    }

    int left = l - 1, right = l;
    vector<int> ans;

    while(k--){
        if(left < 0){
            ans.push_back(arr[right++]);
        }else if (right >= n) {
            ans.push_back(arr[left--]);
        }else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
            ans.push_back(arr[left--]);
        }else {
            ans.push_back(arr[right++]);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}