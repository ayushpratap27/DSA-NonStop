#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postToInfix(string postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (!isOperator(c)) {
            // Operand, push it onto the stack as a string
            s.push(string(1, c));
        } else {
            // Operator, pop two operands from the stack, concatenate them with the operator, and push the result back onto the stack
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();

            string result = "(" + operand1 + c + operand2 + ")";
            s.push(result);
        }
    }

    // The final result is on top of the stack
    return s.top();
}