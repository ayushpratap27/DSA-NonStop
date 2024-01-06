#include <iostream>
using namespace std;

int flipBits(int A, int B) {
    // XOR A and B to find differing bits
    int xorResult = A ^ B;
    
    int count = 0;
    
    // Count the set bits in XOR result
    while (xorResult) {
        count += xorResult & 1;
        xorResult >>= 1;
    }
    
    return count;
}

int main() {
    int A = 7;
    int B = 12;
    
    int result = flipBits(A, B);
    
    cout << "Number of bits to flip: " << result << endl;
    
    return 0;
}
