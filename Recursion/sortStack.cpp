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

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void SortedStack::sort() {
    // Base case: If the stack is empty, do nothing
    if (s.empty()) {
        return;
    }

    // Step 1: Remove the top element of the stack
    int topElement = s.top();
    s.pop();

    // Step 2: Recursively sort the remaining stack
    sort();

    // Step 3: Insert the removed element back into the sorted position
    if (s.empty() || s.top() <= topElement) {
        s.push(topElement); // If the stack is empty or top element is less, push directly
    } else {
        int temp = s.top(); // Save the current top element
        s.pop();
        s.push(topElement); // Place the removed element
        sort(); // Sort the stack after inserting back
        s.push(temp); // Restore the saved top element
    }
}

// without recursion
void SortedStack::sort() {
    std::stack<int> auxiliaryStack;

    // Iterate through all elements in the original stack
    while (!s.empty()) {
        int current = s.top();
        s.pop();

        // Transfer elements from auxiliaryStack back to s to maintain sorted order
        while (!auxiliaryStack.empty() && auxiliaryStack.top() > current) {
            s.push(auxiliaryStack.top());
            auxiliaryStack.pop();
        }

        // Place the current element in the correct position
        auxiliaryStack.push(current);
    }

    // Move sorted elements back to the original stack
    while (!auxiliaryStack.empty()) {
        s.push(auxiliaryStack.top());
        auxiliaryStack.pop();
    }
}
