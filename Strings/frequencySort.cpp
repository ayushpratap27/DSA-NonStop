#include<bits/stdc++.h>
using namespace std;



struct Compare {
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        return a.second < b.second;
    }
};

string sortByFrequency(int n, string s) {
    unordered_map<char, int> freqMap;

    // Count character frequencies
    for (char c : s) {
        freqMap[c]++;
    }

    // Max heap to sort characters based on frequencies
    priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> maxHeap;

    // Populate the max heap
    for (auto& entry : freqMap) {
        maxHeap.push(entry);
    }

    // Build the result string
    string result = "";
    while (!maxHeap.empty()) {
        pair<char, int> current = maxHeap.top();
        maxHeap.pop();
        result.append(current.second, current.first); // Append the character based on its frequency
    }

    return result;
}