//
// Created by Sifat Ali on 4/19/2024.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // assuming '(' has the lowest precedence
}

string infixToPostfix(string infix) {
    stack<char> opStack;
    string postfix = "";

    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Discard '('
        } else { // Operator
            while (!opStack.empty() && precedence(c) <= precedence(opStack.top())) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c-d)/e";
    string postfix = infixToPostfix(infix);
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}
