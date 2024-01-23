#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());

    for(int i=0;i<n-2;i++){
        
        if(i>0 && arr[i]==arr[i-1]) continue;

        int left = i+1;
        int right = n-1;

        while(left<right){
            int current_sum = arr[i]+arr[left]+arr[right];

            if(current_sum==0){
                result.push_back({arr[i], arr[left], arr[right]});

                // Skip duplicate elements
                while(left<right && arr[left]==arr[left+1]) left++;
                while(left<right && arr[right]==arr[right-1]) right--;

                left++;
                right--;
            }else if(current_sum<0) {
                left++;
            }else{
                right--;
            }
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> result = triplet(n, arr);

    cout << "Triplets with sum zero are:" << endl;
    for (const auto &triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}
