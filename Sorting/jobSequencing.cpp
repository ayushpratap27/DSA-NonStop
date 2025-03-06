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

bool static compare (pair<int, int> &a, pair<int, int> &b){
    return a.first > b.first;
}

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit){
    int cnt = 0;
    int totalProfit = 0;

    vector<pair<int, int>> ok;
    for (int i = 0; i < deadline.size(); i++) {
        ok.push_back({profit[i], deadline[i]});
    }

    sort(ok.begin(), ok.end(), compare);

    int maxdeadline = 0;
    for (auto i : deadline) {
        maxdeadline = max(i, maxdeadline);
    }

    vector<int> valid(maxdeadline + 1, -1);

    for (auto it : ok) {
        int profit = it.first;
        int deadline = it.second;

        for (int j = deadline; j >= 1; j--) {
            if (valid[j] == -1) {
                valid[j] = 1;
                totalProfit += profit;
                cnt++;
                break;
            }
        }
    }

    return {cnt, totalProfit};
}