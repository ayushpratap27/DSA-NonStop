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

struct Node {
    unordered_map<string, Node*> children;
    bool del = false;
};

unordered_map<string, vector<Node*>> seen;
vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    Node* root = new Node();

    for (auto& path : paths)  {
        Node* cur = root;
        for (const string& dir : path)  {
            if (!cur->children.count(dir)) {
                cur->children[dir] = new Node();
            }

            cur = cur->children[dir];
        }
    }

    dfs(root);

    for (auto& [key, nodes] : seen) {
        if (nodes.size() > 1) {
            for (auto* node : nodes) {
                node->del = true;
            }
        }
    }

    vector<vector<string>> res;
    vector<string> path;
    collect(root, path, res);
    return res;
}

string dfs(Node* node) {
    if (node->children.empty()){
        return "";
    } 

    vector<string> subs;
    for (auto& [name, child] : node->children) {
        subs.push_back(name + "(" + dfs(child) + ")");
    }

    sort(subs.begin(), subs.end());
    string serial = accumulate(subs.begin(), subs.end(), string());
    seen[serial].push_back(node);
    return serial;
}

void collect(Node* node, vector<string>& path, vector<vector<string>>& res) {
    for (auto& [name, child] : node->children) {
        if (child->del) {
            continue;
        } 

        path.push_back(name);
        res.push_back(path);
        collect(child, path, res);
        path.pop_back();
    }
}