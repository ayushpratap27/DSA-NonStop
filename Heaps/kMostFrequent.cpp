#include <bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &arr) {
    // Count the frequency of each element in the array
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }

    // Define a lambda function for the custom comparison in the priority queue
    auto compare = [&](int a, int b) {
        return freqMap[a] > freqMap[b];
    };

    // Create a min heap (priority queue) with custom comparison
    priority_queue<int, vector<int>, decltype(compare)> minHeap(compare);

    // Populate the min heap with the first K elements
    for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
        minHeap.push(it->first);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    // Extract the elements from the min heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    // Reverse the result vector to get the elements in any order
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 3};
    int k = 2;

    vector<int> result = KMostFrequent(arr.size(), k, arr);

    cout << "K most frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
