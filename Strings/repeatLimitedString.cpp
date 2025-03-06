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

string repeatLimitedString(string s, int rl){
    vector<int> freq(26, 0);

    for (char c : s){
        freq[c - 'a']++;
    }

    string result = "";
    int largest = 25;
    int second = 24;

    while (largest >= 0){
        while (largest >= 0 && freq[largest] == 0){
            largest--;
        }
        if (largest < 0)
            break;

        int limit = rl;
        while (freq[largest] > 0 && limit > 0){
            result += (char)(largest + 'a');
            freq[largest]--;
            limit--;
        }

        if (freq[largest] == 0){
            largest--;
        }
        else{
            second = largest - 1;
            while (second >= 0 && freq[second] == 0){
                second--;
            }

            if (second < 0)
                break;

            result += (char)(second + 'a');
            freq[second]--;
        }
    }

    return result;
}