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

vector<int> getRow(int rowIndex) {
    if(rowIndex == 0) return {1};
    vector<int> prev(1, 1);

    for(int i = 1; i <= rowIndex; i++) {
        vector<int> temp;
        temp.push_back(1);
        for(int j = 1; j < prev.size(); j++) {
            temp.push_back(prev[j - 1] + prev[j]);
        }
        temp.push_back(1);
        prev = temp;
    }

    return prev;
}

vector<int> getRow(int rowIndex) {
    vector<vector<int>> pascal(rowIndex + 1, vector<int>(rowIndex + 1));
    for (int i = 0; i < rowIndex + 1; i++) {
        pascal[i].resize(i + 1);
        for(int j = 0; j < pascal[i].size(); j++){
            if(j == 0 || i == j){
                pascal[i][j] = 1;
            }else {
                if(i > 0 && j > 0) 
                    pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
        }
    }

    return pascal[rowIndex];
}