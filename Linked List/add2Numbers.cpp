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
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};  


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* curr = dummyNode;
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL) {
        int sum = carry;
        if(temp1) sum += temp1->val;
        if(temp2) sum += temp2->val;

        ListNode* newNode = new ListNode(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1) temp1 = temp1->next;
        if(temp2) temp2 = temp2->next; 
    }

    if(carry) {
        ListNode* node = new ListNode(carry);
        curr->next = node;
    }

    return dummyNode->next;
}