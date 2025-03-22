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

// vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
//     unordered_map<string, int> mp;

//     for(auto& recipe : recipes) {
//         mp[recipe] = 0; 
//     }

//     for(auto& supply : supplies) {
//         mp[supply] = 1; 
//     }

//     vector<string> result;
//     bool updated = true; 

//     while(updated){
//         updated = false; 

//         for(int i = 0; i < recipes.size(); i++) {
//             if(mp[recipes[i]] == 1) continue;
            
//             bool flag = true;
//             for(auto& ing : ingredients[i]) {
//                 if(mp.find(ing) == mp.end() || mp[ing] != 1) {
//                     flag = false;
//                     break;
//                 }
//             }

//             if(flag){
//                 result.push_back(recipes[i]);
//                 mp[recipes[i]] = 1;
//                 updated = true; 
//             }
//         }
//     }

//     return result;
// }

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
    unordered_map<string, int> indegree;
    unordered_map<string, vector<string>> adj;

    for(int i = 0; i < ingredients.size(); i++) {
        for(auto it : ingredients[i]) {
            adj[it].push_back(recipes[i]);
            indegree[recipes[i]]++;
        }
    }

    queue<string> q;
    for(auto it : supplies) {
        q.push(it);
    }

    while(!q.empty()) {
        string str = q.front();
        q.pop();

        for(auto it : adj[str]){
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    vector<string> result;
    for(auto it : indegree) {
        if(it.second == 0) {
            result.push_back(it.first);
        }
    }

    return result;
}