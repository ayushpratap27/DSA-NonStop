#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
	// Write your code here
    int x = 0, y = 0;
    int count1 = 0, count2 = 0;

    for (int num : nums) {
        if (num == x) {
            count1++;
        } else if (num == y) {
            count2++;
        } else if (count1 == 0) {
            x = num;
            count1 = 1;
        } else if (count2 == 0) {
            y = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int num : nums) {
        if (num == x) {
            count1++;
        } else if (num == y) {
            count2++;
        }
    }

    vector<int> result;
    int n = nums.size();
    if (count1 > n / 3) {
        result.push_back(x);
    }
    if (count2 > n / 3) {
        result.push_back(y);
    }

    return result;

}

vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size();
    int cnt1=0, cnt2=0;
    int ele1=INT_MIN, ele2=INT_MIN;

    for(int i=0;i<n;i++){
        if(cnt1==0 && ele2!=nums[i]){
            ele1=nums[i];
            cnt1=1;
        }else if(cnt2==0 && ele1!=nums[i]){
            ele2=nums[i];
            cnt2=1;
        }else if(nums[i]==ele1){
            cnt1++;
        }else if(nums[i]==ele2){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }

        int cnt3=0,cnt4=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1){
                cnt3++;
            }
            if(nums[i]==ele2){
                cnt4++;
            }
        }
        vector<int> result;
        int mini = (int)(n/3)+1;
        if(cnt3>=mini){
            result.push_back(ele1);
        }
        if(cnt4>=mini){
            result.push_back(ele2);
        }
        return result;

}
// T.C.=O(n) S.C.=O(1)