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

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2){
    vector<int> maxFreq(26, 0);
    for (auto word : words2){
        vector<int> freq(26, 0);
        for (int i = 0; i < word.size(); i++){
            freq[word[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++){
            maxFreq[i] = max(maxFreq[i], freq[i]);
        }
    }

    vector<string> ans;
    for (auto word : words1){
        vector<int> freq(26, 0);
        for (int i = 0; i < word.size(); i++){
            freq[word[i] - 'a']++;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++){
            if (freq[i] < maxFreq[i]){
                flag = false;
                break;
            }
        }
        if (flag) {
            ans.push_back(word);
        }
    }

    return ans;
}