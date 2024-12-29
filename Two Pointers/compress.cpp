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

int compress(vector<char>& chars) {
    int n = chars.size();
    int i = 0;
    string s = "";

    while (i < n) {
        char currChar = chars[i];
        int count = 0;

        while (i < n && chars[i] == currChar) {
            count++;
            i++;
        }

        s += currChar;
        if (count != 1) s += to_string(count);
    }

    chars.clear();
    for (char c : s) {
        chars.push_back(c);
    }

    return s.size();
}

    // int compress(vector<char>& chars) {
    //     int n = chars.size();
    //     int i = 0;   
    //     int write = 0;

    //     while (i < n) {
    //         char currentChar = chars[i]; 
    //         int count = 0;

    //         while (i < n && chars[i] == currentChar) {
    //             count++;
    //             i++;
    //         }

    //         chars[write++] = currentChar;

    //         if (count > 1) {
    //             string countStr = to_string(count);
    //             for (char c : countStr) {
    //                 chars[write++] = c;
    //             }
    //         }
    //     }

    //     return write;
    // }