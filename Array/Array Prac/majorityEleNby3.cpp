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

int main(){
    
}