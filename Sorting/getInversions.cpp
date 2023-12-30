#include <iostream>

using namespace std;

long long mergeAndCount(long long arr[], long long temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += mid - i + 1;  // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

long long mergeSortAndCount(long long arr[], long long temp[], int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSortAndCount(arr, temp, left, mid);
        count += mergeSortAndCount(arr, temp, mid + 1, right);
        count += mergeAndCount(arr, temp, left, mid, right);
    }
    return count;
}

long long getInversions(long long arr[], int n) {
    long long* temp = new long long[n];
    long long inversions = mergeSortAndCount(arr, temp, 0, n - 1);
    delete[] temp;
    return inversions;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    long long* arr = new long long[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = getInversions(arr, n);
    cout << "Number of inversions: " << result << endl;

    delete[] arr;
    return 0;
}
