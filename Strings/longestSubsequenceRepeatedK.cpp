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

bool isKRepeatedSubsequence(string& s, string& t, int k) {
    int pos = 0, matched = 0;
    int n = s.size(), m = t.size();
    for(char ch : s){
        if (ch == t[pos]) {
            pos++;
            if (pos == m) {
                pos = 0;
                matched++;
                if (matched == k) {
                    return true;
                }
            }
        }
    }

    return false;
}

string longestSubsequenceRepeatedK(string s, int k) {
    vector<int> freq(26);
    for(char ch : s){
        freq[ch - 'a']++;
    }

    vector<char> candidate;
    for(int i = 25; i >= 0; i--) {
        if(freq[i] >= k) {
            candidate.push_back('a' + i);
        }
    }

    queue<string> q;
    for(char ch : candidate) {
        q.push(string(1, ch));
    }

    string ans = "";
    while(!q.empty()){
        string curr = q.front();
        q.pop();

        if(curr.size() > ans.size()) {
            ans = curr;
        }

        for(auto ch : candidate) {
            string next = curr + ch;
            if(isKRepeatedSubsequence(s, next, k)) {
                q.push(next);
            }
        }
    }

    return ans;
}