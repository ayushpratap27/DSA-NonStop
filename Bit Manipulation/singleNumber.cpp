#include<bits/stdc++.h>
using namespace std;

int singleNumber(const std::vector<int>& nums) {
    int result = 0;
        
    // XOR all elements in the array
    for (int num : nums) {
        result ^= num;
    }

    return result;
}
// T.C.=O(n)   S.C.=O(1)


//************ Using Map to store Freq. ******************
int singleNumber(vector<int>& nums) { 
    unordered_map<int,int> a;
    for(auto x: nums)
	   a[x]++;
    for(auto z:a)
	    if(z.second==1)
	 	   return z.first;
	return -1;
}

// T.C.=O(n)  S.C.=O(n)

