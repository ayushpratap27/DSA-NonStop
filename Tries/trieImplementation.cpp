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
    Node* links[26];
    bool flag = false;
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* temp = root;
        for (char c : word) {
            if (temp->links[c - 'a'] == nullptr) {
                temp->links[c - 'a'] = new Node();
            }
            temp = temp->links[c - 'a'];
        }
        temp->flag = true;
    }

    bool search(string word) {
        Node* temp = root;
        for (char c : word) {
            if (temp->links[c - 'a'] == nullptr) {
                return false;
            }
            temp = temp->links[c - 'a'];
        }
        return temp->flag;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (char c : prefix) {
            if (temp->links[c - 'a'] == nullptr) {
                return false;
            }
            temp = temp->links[c - 'a'];
        }
        return true;
    }
};

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    bool setEnd() {
        flag = true;
    }

    bool isEnd() {
        flag = true;
    }
};

class Trie {
    Node* root; 
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* temp = root;
        for (char c : word) {
            if (!temp->containsKey(c)) {
                temp->put(c, new Node());
            }
            temp = temp->get(c);
        }
        temp->setEnd();
    }

    bool search(string word) {
        Node* temp = root;
        for (char c : word) {
            if (!temp->containsKey(c)) {
                return false;
            } 
            temp = temp->get(c);
        }
        return temp->isEnd();
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (char c : prefix) {
            if (!temp->containsKey(c)) {
                return false;
            }
            temp = temp->get(c);
        }
        return true;
    }
};