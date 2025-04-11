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

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    ListNode* node = head;

    vector<vector<int>> ans(m, vector<int>(n, -1));
    
    while(left <= right && top <= bottom && node){
        for(int i = left; i <= right && node; i++){
            ans[top][i] = node->val;
            node = node->next;
        }
        top++;

        for(int i = top; i <= bottom && node; i++){
            ans[i][right] = node->val;
            node = node->next;
        }
        right--;

        if(top <= bottom){
            for(int i = right; i >= left && node; i--){
                ans[bottom][i] = node->val;
                node = node->next;
            }
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top && node; i--){
                ans[i][left] = node->val;
                node = node->next;
            }
            left++;
        }
    }

    return ans;
}