#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
        int n=nums.size();
        int temp;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if(nums[j]>nums[j+1]){
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
        }
    }

int main(){
    
}