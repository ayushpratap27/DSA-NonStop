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

int countSymmetricIntegers(int low, int high) {
    int count = 0;

    for(int i = low; i <= high; i++) {
        int num = i;
        int idx = 0;
        int prefixsum = 0, suffixSum = 0;
        
        int digits[10]; 
        while(num > 0) {
            digits[idx++] = num % 10;
            num /= 10;
        }
        
        if(idx % 2 == 0) {
            for(int j = 0; j < idx / 2; j++) {
                prefixsum += digits[j];
                suffixSum += digits[idx - j - 1];
            }

            if (prefixsum == suffixSum) count++;
        }
    }

    return count;
}


//**********************************************************************************************************/


int isSymmetric(int n) {
    string str = to_string(n);
    if(str.size() % 2 != 0) return 0;

    int prefixSum = 0;
    int suffixSum = 0;
    for(int i = 0; i < str.size()/2; i++) {
        prefixSum += (str[i] - '0');
        suffixSum += (str[str.size() - i - 1] - '0');
    }

    if(prefixSum == suffixSum) return 1;
    return 0;
}

int countSymmetricIntegers(int low, int high) {
    int cnt = 0;
    for(int i = low; i <= high; i++) {
        if(isSymmetric(i)){
            cnt++;
        }
    }

    return cnt;
}
