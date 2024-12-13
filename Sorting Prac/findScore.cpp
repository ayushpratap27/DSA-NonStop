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

long long findScore(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++){
        v.push_back({nums[i], i});
    }

    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        if (a.first == b.first)
            return a.second < b.second; 
        return a.first < b.first; });

    vector<bool> marked(n, false);
    long long score = 0;

    for (auto &p : v){
        int value = p.first;
        int index = p.second;

        if (!marked[index]){
            score += value;
            marked[index] = true;
            if (index - 1 >= 0) marked[index - 1] = true;
            if (index + 1 < n) marked[index + 1] = true;
        }
    }

    return score;
}