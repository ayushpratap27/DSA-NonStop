#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string postfixToPrefix(string &postfix) {
    stack<string> stack;

    for (char &c : postfix) {
        if (!isOperator(c)) {
            // If it's an operand, push it onto the stack
            stack.push(std::string(1, c));
        } else {
            // If it's an operator, pop two operands from the stack
            string operand2 = stack.top();
            stack.pop();
            string operand1 = stack.top();
            stack.pop();

            // Combine the operands and operator to form a new operand
            string newOperand = c + operand1 + operand2;

            // Push the new operand onto the stack
            stack.push(newOperand);
        }
    }

    // The final result is on the top of the stack
    return stack.top();
}

int main() {
    string postfixExpression = "34*5+";
    string prefixExpression = postfixToPrefix(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << std::endl;
    cout << "Prefix Expression: " << prefixExpression << std::endl;

    return 0;
}
