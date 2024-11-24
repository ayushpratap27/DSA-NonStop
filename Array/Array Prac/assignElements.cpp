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

vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
    int n = groups.size();
    int m = elements.size();
    int maxi = 0;
    for(int num : groups){
        maxi = max(maxi, num);
    }
    vector<int> leastIdx(maxi + 1, -1); 

    for(int i = 0; i < m; i++){
        if(elements[i] <= maxi && leastIdx[elements[i]] == -1) {
            leastIdx[elements[i]] = i; 
        }
    }

    vector<int> assigned(n, -1);

    for(int i = 0; i < n; i++){
        int num = groups[i];
        int idx = INT_MAX;

        for(int d = 1; d * d <= num; d++){
            if(num % d == 0){
                if(leastIdx[d] != -1) idx = min(idx, leastIdx[d]);
                if(d != num / d && leastIdx[num / d] != -1) 
                    idx = min(idx, leastIdx[num / d]);
            }
        }

        assigned[i] = (idx == INT_MAX) ? -1 : idx;
    }

    return assigned;
}