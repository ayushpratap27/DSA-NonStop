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

string reverseWords(string s) {
    int n = s.size();
    reverse(s.begin(), s.end());
    int i = 0;
    int l = 0, r = 0;

    while(i < n) {
        while(i < n && s[i] != ' ') {
            s[r] = s[i];
            i++;
            r++;
        }

        if(l < r) {
            reverse(s.begin() + l, s.begin() + r);
            s[r] = ' ';
            r++;

            l = r;
        }

        i++;
    }

    return s.substr(0, r - 1);
}

// string reverseWords(string s) {
//     int n = s.size();
//     string ans = "";
//     int i = 0;

//     while(i < n) {
//         string temp = "";
//         while(i < n && s[i] == ' ') i++;

//         while(i < n && s[i] != ' '){
//             temp += s[i];
//             i++;
//         }

//         if(!temp.empty()) {
//             if(ans.empty()) ans = temp;
//             else ans = temp + ' ' + ans;
//         }
//     }

//     return ans;
// }

// string reverseWords(string s) {
//     stringstream ss(s);
//     string token = "";
//     string result = "";

//     while(ss >> token) {
//         result = token + ' ' + result;
//     }

//     return result.substr(0, result.size() - 1);
// }