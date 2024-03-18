#include <bits/stdc++.h> 
using namespace std;


int reduceHalfSize(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int> freq;
        int i = 0;
        while(i<n){
            int count = 1;
            while(i < n-1 && arr[i]==arr[i+1]){
                count++;
                i++;
            }
            freq.push_back(count);
            i++;
        }
        sort(freq.begin(),freq.end());

        int sum = 0;
        int count = 0;
        i = freq.size()-1;

        while(i>=0){
            sum += freq[i];
            count++;
            if( sum >= n/2){
                break;
            }
            i--;
        }
        return count;
    }