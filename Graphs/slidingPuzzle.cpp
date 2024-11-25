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

int slidingPuzzle(vector<vector<int>>& board) {
    unordered_map<int, vector<int>> mp;
    mp[0].push_back(1);
    mp[0].push_back(3);
    mp[1].push_back(0);
    mp[1].push_back(2);
    mp[1].push_back(4);
    mp[2].push_back(1);
    mp[2].push_back(5);
    mp[3].push_back(0);
    mp[3].push_back(4);
    mp[4].push_back(1);
    mp[4].push_back(3);
    mp[4].push_back(5);
    mp[5].push_back(2);
    mp[5].push_back(4);

    string begin = "123450";
    string end = "";
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            end += '0' + board[i][j];
        }
    }

    unordered_set<string> vis;
    queue<pair<string, int>> q;
    int steps = 0;
    q.push({begin, 5});
    vis.insert(begin);

    while (!q.empty()){
        int size = q.size();

        while (size--){
            pair<string, int> front = q.front();
            q.pop();
            string curr = front.first;
            if (curr == end)
                return steps;
            int pos = front.second;

            for (auto i : mp[pos]){
                swap(curr[i], curr[pos]);
                if (vis.find(curr) == vis.end()){
                    vis.insert(curr);
                    q.push({curr, i});
                }
                swap(curr[i], curr[pos]);
            }
        }

        steps++;
    }

    return -1;
}