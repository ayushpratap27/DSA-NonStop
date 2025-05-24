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

bool isPrime(long long num) {
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    for(long long i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

long long sumOfLargestPrimes(string s) {
    unordered_set<long long> st;
    int n = s.size();
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n && j - i + 1 <= 10; j++){  
            string substring = s.substr(i, j - i + 1);
            long long num = stoll(substring);
            if(isPrime(num)){
                st.insert(num);
            }
        }
    }

    if(st.empty()) {
        return 0;
    }
    
    vector<long long> vec(st.begin(), st.end());
    sort(vec.rbegin(), vec.rend());
    
    long long sum = 0;
    int cnt = min(3, (int)vec.size());
    for(int i = 0; i < cnt; i++){
        sum += vec[i];
    }
    
    return sum;
}
