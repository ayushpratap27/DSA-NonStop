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

void seperate(const vector<int>& A, vector<int>& A1, vector<int>& A2) {
    for(auto a : A){
        if (a < 0) A1.push_back(-a);
        else A2.push_back(a);
    }
    reverse(begin(A1), end(A1));
}

long long numProductNoGreaterThan(const vector<int>& A, const vector<int>& B, long long m) {
    long long count = 0;
    int n = B.size() - 1;
    for(auto a : A) {
        while (n >= 0 && (long long)a * B[n] > m) n--; 
        count += n + 1;
    }
    return count;
}


long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
    vector<int> A1, A2, B1, B2;
    seperate(nums1, A1, A2);
    seperate(nums2, B1, B2);

    const long long negCount = (long long)A1.size() * B2.size() + (long long)A2.size() * B1.size();
    int sign = 1;

    if(k > negCount) {
        k -= negCount;  //  find (k - negCount)-th positive
    }else {
        k = negCount - k + 1;  // Find (negCount - k + 1)-th abs(negative)
        sign = -1;
        swap(B1, B2);
    }

    long long l = 0, r = 1e10;

    while(l < r) {
        long long m = (l + r) / 2;
        if (numProductNoGreaterThan(A1, B1, m) + numProductNoGreaterThan(A2, B2, m) >= k)
            r = m;
        else
            l = m + 1;
    }

    return sign * l;
}