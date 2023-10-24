#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
    int maximum=nums[0];
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum=sum+nums[i];
        maximum=max(maximum,sum);
        if(sum<0){
            sum=0;
        }
    }

    return maximum;
}

int main(){
    
}