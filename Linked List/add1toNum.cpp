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
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};  

Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    
    return prev;
}

Node* addOne(Node* head) {
    Node* newNode = new Node(1);
    Node* newHead = reverseLL(head);
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry = 0;
    
    while(newHead || newNode) {
        int sum = carry;
        if(newHead) sum += newHead->data;
        if(newNode) sum += newNode->data;
        
        Node* node = new Node(sum % 10);
        carry = sum / 10;
        
        curr->next = node;
        curr = curr->next;
        
        if(newHead) newHead = newHead->next;
        if(newNode) newNode = newNode->next;
    }
    
    if(carry) {
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    
    return reverseLL(dummyNode->next);
}


///         BETTER APPROACH

int helper(Node* temp) {
    if(temp == NULL) return 1;

    int carry = helper(temp->next);

    temp->data += carry;

    if(temp->data < 10) return 0;

    temp->data = 0;

    return 1;
}


Node *addOne(Node *head) {
    int carry = helper(head);

    if(carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}