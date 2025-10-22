#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Operand stack
double operands[MAX];
int top_opd = -1;

// Operator stack
char operators[MAX];
int top_opr = -1;

// Push and pop functions for operands
void push_operand(double val) { operands[++top_opd] = val; }
double pop_operand() { return operands[top_opd--]; }

// Push and pop functions for operators
void push_operator(char op) { operators[++top_opr] = op; }
char pop_operator() { return operators[top_opr--]; }
char peek_operator() { return operators[top_opr]; }

// Function to return precedence
int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '(': return 0; // lowest precedence for '('
    }
    return -1;
}

// Apply an operator to two operands
double apply_operator(char op, double a, double b) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Evaluate the expression
double evaluate(char *exp) {
    int i = 0;
    while(exp[i] != '\0') {
        if(exp[i] == ' ' || exp[i] == '\t') { i++; continue; }

        if(isdigit(exp[i])) {
            double val = 0;
            while(isdigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            if(exp[i] == '.') { // handle decimal
                i++;
                double frac = 0.1;
                while(isdigit(exp[i])) {
                    val += (exp[i]-'0') * frac;
                    frac /= 10;
                    i++;
                }
            }
            push_operand(val);
        } 
        else if(exp[i] == '(') {
            push_operator(exp[i]);
            i++;
        } 
        else if(exp[i] == ')') {
            while(top_opr != -1 && peek_operator() != '(') {
                char op = pop_operator();
                double b = pop_operand();
                double a = pop_operand();
                push_operand(apply_operator(op, a, b));
            }
            pop_operator(); // remove '('
            i++;
        } 
        else { // operator +,-,*,/
            while(top_opr != -1 && precedence(peek_operator()) >= precedence(exp[i])) {
                char op = pop_operator();
                double b = pop_operand();
                double a = pop_operand();
                push_operand(apply_operator(op, a, b));
            }
            push_operator(exp[i]);
            i++;
        }
    }

    // Remaining operators
    while(top_opr != -1) {
        char op = pop_operator();
        double b = pop_operand();
        double a = pop_operand();
        push_operand(apply_operator(op, a, b));
    }

    return pop_operand();
}

int main() {
    char exp[MAX];
    printf("Enter arithmetic expression: ");
    fgets(exp, MAX, stdin);
    exp[strcspn(exp, "\n")] = '\0'; // remove newline

    double result = evaluate(exp);
    printf("Result: %.2lf\n", result);

    return 0;
}
