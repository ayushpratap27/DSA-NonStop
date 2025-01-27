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

bool isSubsequence(string &s1, string &s2){
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {

        if (s1[i] == s2[j]) i++;
        
        j++;
    }
    return i == s1.size();
}

int findLUSlength(vector<string> &strs){
    int n = strs.size();
    int longestSubsequence = -1;

    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        for (int j = 0; j < n; j++) {
            if (i != j && isSubsequence(strs[i], strs[j])) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            longestSubsequence = max(longestSubsequence, (int)strs[i].size());
        }
    }
    return longestSubsequence;
}