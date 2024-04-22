#include<bits/stdc++.h>
using namespace std;

int getWinner(vector<int>& arr, int k) {
    
    if(k>= arr.size()){
        return *max_element(arr.begin(),arr.end());
    }

    int winner = arr[0];
    int cnt = 0;

    for(int i=1;i<arr.size();i++){
        if(winner>arr[i]){
            cnt++;
        }
        else{
            winner = arr[i];
            cnt = 1;
        }
        if(cnt == k){
            return winner;
        }
    }

    return *max_element(arr.begin(),arr.end());

}