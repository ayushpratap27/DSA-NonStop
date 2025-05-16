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

#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& qu) 
    {
        int n=s.size(),q=qu.size();
        vector<vector<int>>ans;  
        unordered_map<ll,pii>map;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(!map.count(0)) map[0]=make_pair(i,i);
                continue;
            }
            long long num=0;
            for(int j=i;j<=min(i+32,n-1);j++){
                num = (num << 1) + (s[j] - '0');
                if(!map.count(num)) map[num] = make_pair(i,j);                
            }
        }
        for(int i=0;i<q;i++){
            int num=qu[i][0] ^ qu[i][1];
            if(map.count(num)) ans.push_back({map[num].f,map[num].s});
            else   ans.push_back({-1,-1});
        }
        return ans;
    }
};