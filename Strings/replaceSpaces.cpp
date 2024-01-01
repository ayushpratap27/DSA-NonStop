#include <bits/stdc++.h>
using namespace std;

string replaceSpaces(string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            // Replace space with "@40"
            str.replace(i, 1, "@40");
            // Skip the characters replaced to avoid infinite loop
            i += 2;
        }
    }
    return str;
}

int main() {
    // Example usage
    string inputString = "This is a sample string.";
    cout << "Original String: " << inputString <<endl;

    replaceSpaces(inputString);

    cout << "Modified String: " << inputString <<endl;

    return 0;
}
