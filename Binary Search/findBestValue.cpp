#include <iostream>
#include <vector>
using namespace std;

int summation(vector<int> &arr, int val){
    int sum = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] > val){
            sum += val;
        }
        else{
            sum += arr[i];
        }
    }
    return sum;
}

int findBestValue(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;
    int minDiff = INT_MAX;
    while (low <= high){
        int mid = (low + high) / 2;
        int sum = summation(arr, mid);
        int diff = abs(target - sum);
        if (diff < minDiff || (diff == minDiff && mid < ans)){
            ans = mid;
            minDiff = diff;
        }
        if (sum < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}