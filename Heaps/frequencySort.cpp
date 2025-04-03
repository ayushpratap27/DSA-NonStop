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



// string frequencySort(string s) {
//     int n = s.size();
//     unordered_map<char, int> freq;

//     for(char ch : s){
//         freq[ch]++;
//     }

//     vector<pair<int, char>> freqPairs;
//     for(auto it : freq){
//         freqPairs.push_back({it.second, it.first});
//     }

//     sort(freqPairs.rbegin(), freqPairs.rend()); 

//     string result;
//     // for(int i = 0; i < freqPairs.size(); i++){
//     //     for(int j = 0; j < freqPairs[i].first; j++){
//     //         result += freqPairs[i].second;
//     //     }
//     // }
//     for(auto it : freqPairs){
//         result.append(it.first, it.second);
//     }

//     return result;
// }
                        
typedef pair<char, int> P;

struct compare {
    bool operator() (P &p1, P &p2) {
        return p1.second < p2.second;
    }
};

string frequencySort(string s) {
    priority_queue<P, vector<P>, compare> pq;
    unordered_map<char, int> mp;
    
    for(char ch : s) {
        mp[ch]++; 
    }
    
    for(auto it : mp) {
        pq.push({it.first, it.second});
    }
    
    string res = "";
    
    while(!pq.empty()) {
        P temp = pq.top();
        pq.pop();
        
        res += string(temp.second, temp.first);
    }
    
    return res;
}
