#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n=nums.size();
    int p=0;
    int count;

    while(p<=n){
        for(int i=0;i<n;i++){
            if(nums[i]==p){
                p++;
            }else{
                count=p;
            }
        }
    }

    return count;
}

int main(){

}