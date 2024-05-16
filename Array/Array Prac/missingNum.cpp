#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n=nums.size();
    int sum=(n*(n+1))/2;
    int arrSum=0;
    for(int i=0;i<n;i++){
        arrSum+=nums[i];
    }

    int x=sum-arrSum;
        
    return x;
}

/*
int missingNumber(vector<int>&nums){
    int n=nums.size();
    int result=n;
    for(int i=0; i<n; i++){
        result=result^i^nums[i];
    }
    return result;
}


Code Explanation
Function Signature

int missingNumber(vector<int>& nums)

This function takes a reference to a vector of integers, nums, 
which contains numbers from 0 to nn with one number missing.

int n = nums.size();
int result = n;

n is the size of the vector, which means there are n elements in the vector.
result is initialized to n. This will be used to store the result of 
the XOR operations and eventually hold the missing number.

for(int i = 0; i < n; i++) {
    result = result ^ i ^ nums[i];
}

This loop iterates over all elements in the vector.
The key operation inside the loop is the XOR operation: result = result ^ i ^ nums[i].

XOR Operation Explanation

The XOR (exclusive OR) operation has some useful properties:

    a⊕a=0a⊕a=0 (any number XORed with itself is 0).
    a⊕0=aa⊕0=a (any number XORed with 0 is the number itself).
    XOR is commutative and associative, meaning the order of operations doesn’t matter.

Detailed Steps

    Initialization: result is set to n.

    Loop Through the Array:
        In each iteration, result is updated by XORing it with the current index i 
        and the corresponding element in the array nums[i].

    Why XOR Works:
        If we XOR all indices from 0 to n−1n−1 and all elements in the array, each number 
        from 0 to n−1n−1 will appear twice except the missing number and the number n.
        Since XORing a number with itself results in 0, all paired numbers will cancel out, 
        leaving 0 XORed with the missing number and n.

    Final Result:
        After the loop, result will effectively be 0 ^ missing_number ^ n, but since n was initially
        included in result, the final value of result will just be the missing number.

Example

Consider an example where nums = [3, 0, 1]:

    n (size of nums) is 3.
    Initial result is set to 3.

Loop iterations:

    i = 0: result = 3 ^ 0 ^ 3 = 0
    i = 1: result = 0 ^ 1 ^ 0 = 1
    i = 2: result = 1 ^ 2 ^ 1 = 2

After the loop, result equals 2, which is the missing number in the array [3, 0, 1].

Conclusion:-

The function uses the properties of XOR to efficiently find the missing number in 
linear time with constant space complexity, which is optimal for this problem.

*/