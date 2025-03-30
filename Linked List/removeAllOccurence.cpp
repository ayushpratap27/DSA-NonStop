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

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) , prev(nullptr) {}
};

//     FOR SINGLY LINKED LIST
ListNode* removeElements(ListNode* head, int val) {
    while(head && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    ListNode* temp = head;
    ListNode* prev = NULL;

    while(temp) {
        if(temp->val == val) {
            prev->next = temp->next;
            delete temp;
            temp = prev->next; 
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

//     FOR DOUBLY LINKED LIST

ListNode * deleteAllOccurrences(ListNode* head, int k) {
    if(!head) return NULL;

    ListNode* temp = head;
    while(temp) {
        if(temp->val == k) {
            if(temp == head) {
                head = head->next;
            }
            ListNode* nextNode = temp->next;
            ListNode* prev = temp->prev;

            if(nextNode) nextNode->prev = prev;
            if(prev) prev->next = nextNode;
            
            delete temp;
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }

    return head;
}