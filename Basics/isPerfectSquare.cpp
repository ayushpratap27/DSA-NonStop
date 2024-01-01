#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num) {
    // Base case: 0 and 1 are perfect squares
    if (num == 0 || num == 1) {
        return true;
    }

    // Binary search
    long long left = 0, right = num;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == num) {
            return true;  // Found a perfect square
        } else if (square < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;  // If no perfect square is found
}

int main() {
    // Example usage
    int num = 16;
    if (isPerfectSquare(num)) {
        std::cout << num << " is a perfect square." << std::endl;
    } else {
        std::cout << num << " is not a perfect square." << std::endl;
    }

    return 0;
}
