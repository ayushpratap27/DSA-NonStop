#include<bits/stdc++.h>
using namespace std;


void findCombinations(vector<int>&arr,int target,vector<int>&current,int start,vector<vector<int>> &result){
    if(target==0){
        result.push_back(current);
        return;
    }

    for(int i=start;i<arr.size() && arr[i]<=target;i++){
        current.push_back(arr[i]);
        findCombinations(arr,target-arr[i],current,i,result);
        current.pop_back();
    }
}

vector<vector<int>> combSum(vector<int> &arr,int B) {
    vector<vector<int>>result;
    vector<int>current;
    sort(arr.begin(),arr.end());

    findCombinations(arr,B,current,0,result);

    return result;
}
