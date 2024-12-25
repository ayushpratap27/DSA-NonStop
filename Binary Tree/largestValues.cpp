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


vector<int> largestValues(TreeNode* root) {
    if (root == nullptr) {
        return vector<int>{};
    }
        
    vector<int> ans;
    queue<TreeNode*> queue;
    queue.push(root);
        
    while (!queue.empty()) {
        int currentLength = queue.size();
        int currMax = INT_MIN;
        
        for (int i = 0; i < currentLength; i++) {
            TreeNode* node = queue.front();
            queue.pop();
            currMax = max(currMax, node->val);
            
            if (node->left) {
                queue.push(node->left);
            }
            
            if (node->right) {
                queue.push(node->right);
            }
        }
            
        ans.push_back(currMax);
    }
        
    return ans;
}


// class Solution {
// public:
//     vector<int> ans;
    
//     vector<int> largestValues(TreeNode* root) {
//         dfs(root, 0);
//         return ans;
//     }
    
//     void dfs(TreeNode* node, int depth) {
//         if (node == nullptr) {
//             return;
//         }
        
//         if (depth == ans.size()) {
//             ans.push_back(node->val);
//         } else {
//             ans[depth] = max(ans[depth], node->val);
//         }
        
//         dfs(node->left, depth + 1);
//         dfs(node->right, depth + 1);
//     }
// };