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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int amountOfTime(TreeNode *root, int start){
    if (!root) return 0;

    vector<vector<int>> adj(100001);
    queue<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        TreeNode *node = nodes.front();
        nodes.pop();

        if (!node) continue;
        if (node->left) {
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            nodes.push(node->left);
        }
        if (node->right) {
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            nodes.push(node->right);
        }
    }

    vector<int> vis(100001, 0);
    queue<pair<int, int>> q;
    q.push({0, start});
    vis[start] = 1;
    int maxTime = 0;

    while (!q.empty()) {
        int time = q.front().first;
        int node = q.front().second;
        q.pop();
        maxTime = max(maxTime, time);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({time + 1, it});
            }
        }
    }

    return maxTime;
}