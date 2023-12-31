#include<bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2) {
    int carry = 0;
    string result = "";

    // Make both strings of equal length by adding leading zeros
    while (num1.length() < num2.length()) {
        num1 = "0" + num1;
    }
    while (num2.length() < num1.length()) {
        num2 = "0" + num2;
    }

    // Traverse the strings in reverse order and add digits
    for (int i = num1.length() - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0';

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }

    // If there is a carry after the loop, add it to the result
    if (carry > 0) {
        result = char(carry + '0') + result;
    }

    return result;
}

int main() {
    // Example usage:
    string num1 = "123";
    string num2 = "456";

    string sum = addStrings(num1, num2);

    cout << "Sum: " << sum << endl;

    return 0;
}
