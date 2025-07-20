#include <bits/stdc++.h>
using namespace std;

// Function to define precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to apply an operator to two numbers
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // Assumes b != 0
    }
    return 0;
}

// Function to evaluate the top of stacks
void evaluateTop(stack<int>& nums, stack<char>& ops) {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    char op = ops.top(); ops.pop();
    nums.push(applyOp(a, b, op));
}

// Function to evaluate the expression
int evaluate(string s) {
    stack<int> nums;
    stack<char> ops;
    int num = 0;
    int n = s.size();
    bool buildingNumber = false;

    for (int i = 0; i < n; ++i) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            buildingNumber = true;
        }

        if (!isdigit(c) && c != ' ' || i == n - 1) {
            if (buildingNumber) {
                nums.push(num);
                num = 0;
                buildingNumber = false;
            }

            if (c == ' ') continue;

            if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (!ops.empty() && ops.top() != '(')
                    evaluateTop(nums, ops);
                if (!ops.empty()) ops.pop(); // pop '('
            } else { // operator + - * /
                while (!ops.empty() && precedence(ops.top()) >= precedence(c))
                    evaluateTop(nums, ops);
                ops.push(c);
            }
        }
    }

    while (!ops.empty())
        evaluateTop(nums, ops);

    return nums.top();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);  // Input: 2*(3+(4-1))
    cout << "Result: " << evaluate(expr) << endl;
    return 0;
}
