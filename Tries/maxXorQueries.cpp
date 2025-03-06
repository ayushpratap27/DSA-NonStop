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
	Node* links[2];

	bool containsKey(int ind) {
		return (links[ind] != NULL);
	}

	Node* get(int ind) {
		return links[ind];
	}

	void put(int ind, Node* node){
		links[ind] = node;
	}
};

class Trie {
	Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insert(int num) {
		Node* node = root;
		for(int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if(!node->containsKey(bit)) {
				node->put(bit, new Node());
			}
			node = node->get(bit);
		}
	}

	int findMax(int num) {
		Node* node = root;
		int maxNum = 0;
		for(int i = 31; i >= 0; i--) {
			int bit = (num >> i) & 1;
			if(node->containsKey(!bit)) {
				maxNum = maxNum | (1 << i);
				node = node->get(!bit);
			}else {
				node = node->get(bit);
			}
		}

		return maxNum;
	}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {
	sort(arr.begin(), arr.end());
	vector<pair<int, pair<int, int>>> offlineQueries;
	int q = queries.size();

	for(int i = 0; i < q; i++) {
		offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
	}

	sort(offlineQueries.begin(), offlineQueries.end());
	vector<int> ans(q, 0);
	int ind = 0;
	int n = arr.size();
	Trie trie;
	for(int i = 0; i < q; i++) {
		int ai = offlineQueries[i].first;
		int xi = offlineQueries[i].second.first;
		int qInd = offlineQueries[i].second.second;

		while(ind < n && arr[ind] <= ai) {
			trie.insert(arr[ind]);
			ind++;
		}
		if(ind == 0) ans[qInd] = -1;
		else ans[qInd] = trie.findMax(xi);
	}

	return ans;
}