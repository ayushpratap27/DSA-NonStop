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

int minLengthAfterRemovals(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = n/2;
    if(n%2 != 0) j = ceil(n/2) + 1;
    int cnt = 0;
    while(j < n){
        if(nums[i] < nums[j]){
            i++;
            j++;
            cnt += 2;
        } else {
            j++;
        }
    }

    return n - cnt;
}

// using map
/*
We store the count of the element that occurs maximum number of times.

Notice that if the count of max occuring element is less than n/2 times, then the element can be cancelled by 
remaining elements (It is given that elements are sorted in non-decreasing order. Hence all remaining elements
will be cancelled amongst themselves). In this case, if array size is even, then we say that ans is 0 and 1 
incase the array size is odd. Because after cancelling all elements, 1 element is still remaining at the end.

If the element occurs more than n/2 times, so now it cannot cancel all elements. But it will still cancel all 
remaining elements.
How many elements are remaining? The elements remaining are (n - maxi). So elements left are maxi - (n - maxi) = 2*maxi - n;
*/

int minLengthAfterRemovals(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i : nums){
        mp[i]++;
    }

    int maxi = 0;
    for(auto it : mp){
        maxi = max(maxi, it.second);
    }

    if(maxi <= n/2){
        if(n % 2){
            return 1;
        }
        else{
            return 0;
        }
    }

    return maxi - (n - maxi);        
        
}