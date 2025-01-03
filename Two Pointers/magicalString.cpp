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

int magicalString(int n){
    if (n <= 3) return 1;

    string s = "122";
    int currIdx = 2;
    int prevNum = 1;
    int count = 1;

    while (s.length() < n){
        if (s[currIdx] == '2') {
            if (prevNum == 1) {
                s += "11";
                count += 2;
                prevNum = 0;
            }
            else {
                s += "22";
                prevNum = 1;
            }
        }
        else {
            if (prevNum == 1) {
                s += "1";
                count += 1;
                prevNum = 0;
            }
            else {
                s += "2";
                prevNum = 1;
            }
        }
        currIdx++;
    }

    if (s.length() == n) return count;
    else if (s[s.length() - 1] == '1') return count - 1;
    else return count;
}