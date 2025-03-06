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

int calculateDigitSum(int num){
    int digitSum = 0;
    while (num > 0) {
        digitSum += num % 10;
        num /= 10;
    }
    return digitSum;
}

int maximumSum(vector<int> &nums) {
    vector<priority_queue<int, vector<int>, greater<int>>> digitSumGroups(82);

    int maxPairSum = -1;

    for (int number : nums) {
        int digitSum = calculateDigitSum(number);
        digitSumGroups[digitSum].push(number);

        if (digitSumGroups[digitSum].size() > 2) {
            digitSumGroups[digitSum].pop(); 
        }
    }

    for (auto &minHeap : digitSumGroups) {
        if (minHeap.size() == 2) {
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            maxPairSum = max(maxPairSum, first + second);
        }
    }

    return maxPairSum;
}
