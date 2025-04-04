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

// Brute Force using recursion

// class Solution {
//     int K;
//     int n;
//     priority_queue<int, vector<int>, greater<int>> pq;

//     void removeFromPQ(int num) {
//         vector<int> temp;

//         while(!pq.empty()) {
//             int x = pq.top();
//             pq.pop();

//             if(x == num) break;

//             temp.push_back(x);
//         }

//         for(int it : temp) pq.push(it);
//     }

//     long long solve(vector<int> &nums1, vector<int> &nums2, int sum, int min, int i, int count) {
//         if(count == K){
//             return sum * min;
//         }

//         if(i >= n) return 0;

//         pq.push(nums2[i]);

//         int take = solve(nums1, nums2, sum + nums1[i], pq.top(), i + 1, count + 1);

//         removeFromPQ(nums2[i]);

//         int not_take = solve(nums1, nums2, sum, min, i + 1, count);

//         return max(take, not_take);
//     }
// public:
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         K = k;
//         n = nums1.size();

//         return solve(nums1, nums2, 0, 0, 0, 0);
//     }
// };

//******************************************************************************************************** */
// Optimized using sorting and priority queue

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> pairs;
    int n = nums1.size();

    for(int i = 0; i < n; i++) {
        pairs.push_back({nums2[i], nums1[i]});
    }

    sort(pairs.rbegin(), pairs.rend());  // Sort by nums2[i] in descending order

    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0, maxScore = 0;

    for(int i = 0; i < n; i++) {
        int val = pairs[i].second;
        int minVal = pairs[i].first;

        sum += val;
        pq.push(val);

        if(pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }

        if(pq.size() == k) {
            maxScore = max(maxScore, sum * 1LL * minVal);
        }
    }

    return maxScore;
}