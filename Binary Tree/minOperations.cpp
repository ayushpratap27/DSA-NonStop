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

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findMinSwaps(vector<int> &values){
    int n = values.size();
    int min_swaps = 0;
    map<int, int> sorted_map;
    for (int j = 0; j < n; j++){
        sorted_map[values[j]] = j;
    }

    sort(values.begin(), values.end());
    vector<bool> visited(n, false);
    int iteration = 0;
    for (auto &[val, idx] : sorted_map){
        if (visited[idx]){
            iteration++;
            continue;
        }
        visited[idx] = true;
        int len = 1;
        while (idx != iteration){
            idx = sorted_map[values[idx]];
            visited[idx] = true;
            len++;
        }
        min_swaps += len - 1;
        iteration++;
    }

    return min_swaps;
}

int minimumOperations(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);
    int min_swaps = 0;

    while (!q.empty()){
        int size = q.size();
        vector<int> values;
        for (int i = 0; i < size; i++){
            TreeNode *curr = q.front();
            q.pop();

            values.push_back(curr->val);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        min_swaps += findMinSwaps(values);
    }

    return min_swaps;
}
