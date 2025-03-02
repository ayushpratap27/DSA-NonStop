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

vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
    sort(items1.begin(), items1.end());
    sort(items2.begin(), items2.end());

    int n = items1.size();
    int m = items2.size();
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(items1[i][0] < items2[j][0]){
            if(!mp[items1[i][0]]){
                ans.push_back({items1[i][0], items1[i][1]});
            }
            mp[items1[i][0]]++;
            i++;
        }else if(items1[i][0] == items2[j][0]){
            if(!mp[items1[i][0]]){
                ans.push_back({items1[i][0], items1[i][1] + items2[j][1]});
            }
            mp[items1[i][0]]++;
            i++;
            j++;
        }else{
            if(!mp[items2[j][0]]){
                ans.push_back({items2[j][0], items2[j][1]});
            }
            mp[items2[j][0]]++;
            j++;
        }
    }

    while(i < n){
        ans.push_back({items1[i][0], items1[i][1]});
        i++;
    }

    while(j < m){
        ans.push_back({items2[j][0], items2[j][1]});
        j++;
    }

    return ans;
}