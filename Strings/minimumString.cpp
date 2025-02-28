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

string getMinString(string a, string b) {  
    return (a.size() < b.size() || (a.size() == b.size() && a < b) )?a : b;
}

string addTwoStrings(string &a, string &b){ 
    if(b.find(a) != string::npos) return b; 
    for(int i = 0; i < a.size(); ++i){
        string t1 = a.substr(i), t2 = b.substr(0,  t1.size());
        if(t1 == t2) return a + b.substr(t1.size());
    }
    return a+b;
}

string solve(string& a, string& b, string& c) {  
    string t1 = addTwoStrings(a, b), t2 = addTwoStrings(b, a);
    string res1 = getMinString(addTwoStrings(t1, c), addTwoStrings(c, t1));
    string res2 = getMinString( addTwoStrings(t2, c), addTwoStrings(c, t2));
    return getMinString(res1, res2);
}

string minimumString(string a, string b, string c) { 
    string res = getMinString( solve(a, b, c), solve(b, c, a));
    return getMinString( res , solve(c,a,b));
}