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
    int endWith = 0;
    int countPrefix = 0;

    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }

    Node* get(char c) {
        return links[c - 'a'];
    }

    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }

    void increaseEnd() {
        endWith++;
    }

    void increasePrefix() {
        countPrefix++;
    }

    void deleteEnd() {
        endWith--;
    }

    void reducePrefix() {
        countPrefix--;
    }

    int getEnd() {
        return endWith;
    }

    int getPrefix() {
        return countPrefix;
    }

};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            char currentChar = word[i];
            if (!node->containsKey(currentChar)) {
                node->put(currentChar, new Node());
            }
            node = node->get(currentChar);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            char currentChar = word[i];
            if (!node->containsKey(currentChar)) {
                return 0;
            }
            node = node->get(currentChar);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            char currentChar = prefix[i];
            if (!node->containsKey(currentChar)) {
                return 0;
            }
            node = node->get(currentChar);
        }
        return node->getPrefix();
    }

    void erase(string word) {
        if (countWordsEqualTo(word) > 0) {
            Node* node = root;
            for (int i = 0; i < word.size(); i++) {
                if(node->containsKey(word[i])) {
                    node = node->get(word[i]);
                    node->reducePrefix();
                } else {
                    return;
                }
            }
            node->deleteEnd();
        }
    }
};