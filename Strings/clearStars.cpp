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

typedef pair<char, int> p;

struct compare {
    bool operator()(p &P1, p &P2) {
        if(P1.first != P2.first) return P1.first > P2.first;
        
        return P1.second < P2.second;
    }
};


string clearStars(string &s) {
    int n = s.size();
    priority_queue<p, vector<p>, compare> pq;

    for (int i = 0; i < n; i++) {
        if (s[i] != '*') {
            pq.push({s[i], i});
        } else {
            if (!pq.empty()) {
                s[pq.top().second] = '*'; 
                pq.pop();
            }
        }
    }
    
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != '*'){
            s[idx++] = s[i];
        }
    }
    
    s.resize(idx);

    return s;
}