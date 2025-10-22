#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return (top >= 0) ? stack[top] : '\0';
}

// Precedence function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Apply operator to two numbers
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
    }
    return 0;
}

int evaluate(const char *exp) {
    int values[MAX];
    int vtop = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == ' ') continue;

        if (isdigit(exp[i])) {
            int val = 0;
            while (isdigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            values[++vtop] = val;
        }

        else if (exp[i] == '(') {
            push('(');
        }

        else if (exp[i] == ')') {
            while (peek() != '(') {
                char op = pop();
                int val2 = values[vtop--];
                int val1 = values[vtop--];
                values[++vtop] = applyOp(val1, val2, op);
            }
            pop(); // remove '('
        }

        else {
            while (top != -1 && precedence(peek()) >= precedence(exp[i])) {
                char op = pop();
                int val2 = values[vtop--];
                int val1 = values[vtop--];
                values[++vtop] = applyOp(val1, val2, op);
            }
            push(exp[i]);
        }
    }

    while (top != -1) {
        char op = pop();
        int val2 = values[vtop--];
        int val1 = values[vtop--];
        values[++vtop] = applyOp(val1, val2, op);
    }

    return values[vtop];
}

int main() {
    char expression[100];

    printf("Enter arithmetic expression: ");
    scanf("%[^\n]", expression);

    int result = evaluate(expression);
    printf("Result: %d\n", result);

    return 0;
}
