#include<bits/stdc++.h>
using namespace std;

//      Swap Numbers
/*
    a = a^b
    b = a^b = (a^b)^b = a
    a = a^b = (a^b)^b = (a^b)^a = b

*/

// Check if the ith bit is set or not
/*  using left shift operator

    Let n = 13  i = 2
    1 1 0 1
  &   1 0 0     1 << i(2)
    -------
    0 1 0 0

    if((n & (1 << i)) != 0) set
    else not set

    Using Right Shift
    if((n >> i) & 1 == 0) not set
    else set
*/
//   T.C. = O(1)  S.C. = O(1)


//  Set the ith bit
/*
    n | (1 << i)

    n = 9   i = 2
    1 0 0 1
  | 0 1 0 0
   ---------
    1 1 0 1

*/


// Clear the ith bit (turn 1 to 0)
/*
    n & ~(1 << i)

*/


// Toggle the ith bit (1 to 0 and 0 to 1)
/*
    n ^ (1 << i)
*/


// Remove the last set bit (rightmost)
/*
    n & n-1

    n = 40   1 0 1 0 0 0
    n-1=39 & 1 0 0 1 1 1 
            -------------
             1 0 0 0 0 0

    n = 84
    n-1=83    1 0 1 0 1 0 0
            & 1 0 1 0 0 1 1
             ---------------
              1 0 1 0 0 0 0
    
*/


// Check if the number is a power of 2
/*
    if(n & (n-1) == 0) then it is power of 2
    else not  
*/


// Count the number of set bits
int countSetBits(int n){
    int cnt = 0;
    // while(n > 1){
    //     if(n%2 == 1) cnt++;
    //     n = n/2;
    // }

    // while(n > 1){
    //     cnt += n&1; // For checking whether it is odd or not
    //     n = n >> 1; // n >> 1 = n/2
    // }

    while(n != 0){ // Better approach
        n = n & (n-1);
        cnt++; 
    }// T.C. = O(no. of set bits) = O(31) for worst case

    if(n == 1) cnt++;

    return cnt;
}
// Using STL
// __builtin_popcount(n)