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

int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    int prev = 0;
    vector<int> gaps;
    for (int i = 0; i < startTime.size(); i++) {
        gaps.push_back(startTime[i] - prev);
        prev = endTime[i];
    }
    gaps.push_back(eventTime - prev);
    for (int i = 0; i < gaps.size(); i++) {
        cout << gaps[i] << " ";
    }

    sort(gaps.begin(), gaps.end());

    prev = 0;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int interval = endTime[i] - startTime[i];
        int left = startTime[i] - prev;
        int right = 0;
        if (i + 1 < n) {
            right = startTime[i + 1] - endTime[i];
        }
        else {
            right = eventTime - endTime[i];
        }
        int idx = gaps.size() - 1;
        while (idx >= 0) {
            if (gaps[idx] == left) {
                left = -1;
            }
            else if (gaps[idx] == right) {
                right = -1;
            }
            else if (gaps[idx] >= interval) {
                if (i + 1 < n) {
                    ans = max(ans, startTime[i + 1] - prev);
                }
                else {
                    ans = max(ans, eventTime - prev);
                }
                break;
            }
            else {
                if (i + 1 < n) {
                    ans = max(ans, startTime[i + 1] - prev - endTime[i] + startTime[i]);
                }
                else {
                    ans = max(ans, eventTime - prev - endTime[i] + startTime[i]);
                }
                break;
            }
            idx--;
        }
        prev = endTime[i];
    }

    return ans;
}