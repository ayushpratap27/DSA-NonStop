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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left) {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right) {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track, target);

    unordered_map<TreeNode*, bool> vis;
    queue<TreeNode*> q;
    q.push(target);
    vis[target] = true;
    int curr_level = 0;

    while(!q.empty()) {
        int size = q.size();
        if(curr_level++ == k) break;
        for(int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left && !vis[curr->left]){
                q.push(curr->left);
                vis[curr->left] = true;
            }
            if(curr->right && !vis[curr->right]){
                q.push(curr->right);
                vis[curr->right] = true;
            }
            if(parent_track[curr] && !vis[parent_track[curr]]) {
                q.push(parent_track[curr]);
                vis[parent_track[curr]] = true;
            }
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        ans.push_back(curr->val);
    }

    return ans;
}