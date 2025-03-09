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

vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<long long> ans(n, 0);

    vector<pair<int, int>> idx;
    for(int i = 0; i < n; i++){
        idx.push_back({nums1[i], i});
    } 

    sort(idx.begin(), idx.end());

    priority_queue<int, vector<int>, greater<int>> pq;  
    unordered_map<int, long long> mp;
    long long sum = 0;
    int j = 0;

    for(int i = 0; i < n; i++){
        int index = idx[i].second;

        while(j < i){
            int prev = idx[j].second;
            if (idx[j].first >= idx[i].first) break;

            pq.push(nums2[prev]);
            sum += nums2[prev];

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            j++;
        }

        mp[index] = sum;
    }

    for(int i = 0; i < n; i++){
        ans[i] = mp[i];            
    } 

    return ans;
}