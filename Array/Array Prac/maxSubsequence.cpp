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

bool cmpfun( pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;

}

vector<int> maxSubsequence(vector<int>& nums, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < nums.size(); i++) {
        pq.push({nums[i], i});
        if (pq.size() > k) pq.pop();
    }

    vector<pair<int, int>> vec;
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        vec.push_back(temp);
    }

    sort(vec.begin(),vec.end(),cmpfun) ;

    vector<int>ans;
    for(auto ele:vec){
        ans.push_back(ele.first);
    }

    return ans;
    
    // while (k) {
    //     ans[pq.top().second] = pq.top().first;
    //     pq.pop();
    //     k--;
    // }

    // vector<int> result(k);
    // for (int i = 0; i < nums.size(); i++) {
    //     if (ans[i] != INT_MIN)
    //         result.push_back(ans[i]);
    // }

    // return result;
}