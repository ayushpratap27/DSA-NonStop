#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {

    //Right rotation
    int n=nums.size();
    k=k%n;
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    }

int main(){
    
}