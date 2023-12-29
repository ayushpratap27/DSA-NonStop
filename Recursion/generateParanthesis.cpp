#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("", n, n, result);
        return result;
    }

private:
    void generate(string current, int left, int right, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }

        if (left > 0) {
            generate(current + '(', left - 1, right, result);
        }

        if (right > left) {
            generate(current + ')', left, right - 1, result);
        }
    }
};

int main() {
    // Example usage:
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    cout << "Combinations of well-formed parentheses:" << endl;
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}
