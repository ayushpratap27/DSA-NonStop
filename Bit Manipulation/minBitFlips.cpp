#include<bits/stdc++.h>
using namespace std;


int minBitFlipsToConvertNum(int start, int goal) {
    int xorResult = start ^ goal;
    int cnt = 0;

    while (xorResult) {
        cnt += xorResult & 1;
        xorResult >>= 1;
    }

    return cnt;
}


int main(){
    int result = minBitFlipsToConvertNum(3,4);

    cout<<result<<endl;
}
/*
The time complexity of this solution is O(log(max(A, B))), where max(A, B) is the maximum of A and B. 
This is because the while loop runs for the number of bits in the maximum of A and B, which is 
proportional to log(max(A, B)).

The space complexity of this solution is O(1) because it only uses a constant amount of extra space 
regardless of the input size.
*/

int getBit(int n, int pos)
{
    if (n & (1 << (pos - 1)))
    {
        return 1;
    }
    return 0;
}
int minBitFlips(int start, int goal)
{
    int count = 0;
    for (int i = 1; i < 32; i++)
    {
        if (getBit(start, i) ^ getBit(goal, i))
        {
            count++;
        }
    }
    return count;
}

/*
The time complexity of the minBitFlips function is O(1) because it iterates 
through a fixed number of bits (32 bits) regardless of the input size. 
The space complexity is also O(1) because the function only uses a constant amount of extra 
space for variables and does not depend on the input size.
*/