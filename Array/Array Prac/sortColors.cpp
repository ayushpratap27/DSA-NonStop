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

/*
counting the number of each color (0s, 1s, and 2s) and then overwriting the 
array with the appropriate number of each color.
This approach also has a time complexity of O(n) and a space complexity of O(1).
*/

void sortColors(vector<int>& nums) {
    
    int count0 = 0, count1 = 0, count2 = 0;
    for (int num : nums) {
        if (num == 0) {
            count0++;
        } else if (num == 1) {
            count1++;
        } else if (num == 2) {
            count2++;
        }
    }
    
    int index = 0;
    while (count0 > 0) {
        nums[index++] = 0;
        count0--;
    }
    while (count1 > 0) {
        nums[index++] = 1;
        count1--;
    }
    while (count2 > 0) {
        nums[index++] = 2;
        count2--;
    }
}


