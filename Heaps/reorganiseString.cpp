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

string reorganizeString(string s) {
    int n = s.size();
    vector<int> freq(26, 0);
    priority_queue<pair<int, char>> pq;

    for(int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;

        if(freq[s[i] - 'a'] > (n + 1) / 2) return "";
    }

    for(int i = 0; i < 26; i++){
        if(freq[i] > 0) {
            pq.push({freq[i], i + 'a'});
        }
    }

    string res = "";
    while(pq.size() >= 2) {
        auto top = pq.top();
        pq.pop();
        auto next = pq.top();
        pq.pop();

        res += top.second;
        res += next.second;

        if(top.first - 1 != 0) pq.push({top.first - 1, top.second});
        if(next.first - 1 != 0) pq.push({next.first - 1, next.second});
    }

    if(!pq.empty()) {
        res += pq.top().second;
    }

    return res;
}