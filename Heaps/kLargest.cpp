#include <bits/stdc++.h>
using namespace std;

vector<int> kLargest(int arr[], int n, int k) {
    // Create a min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Iterate through the array
    for (int i = 0; i < n; ++i) {
        // If the size of the heap is less than k, just push the element
        if (minHeap.size() < k) {
            minHeap.push(arr[i]);
        } else {
            // If the size is equal to k, compare the current element with the smallest element in the heap
            // If it's larger, replace the smallest element with the current element
            if (arr[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }
    }

    // Create a vector to store the k largest elements
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    // Reverse the vector to get elements in descending order
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    vector<int> result = kLargest(arr, n, k);

    cout << "K largest elements: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
