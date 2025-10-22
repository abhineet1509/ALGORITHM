#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

char input[MAX];
int ip = 0;

void error() { printf("Parsing Error!\n"); exit(0); }

// Check terminal match
int match(char t) {
    return t == input[ip];
}

void parse() {
    push('$');
    push('E'); // start symbol

    while(top >= 0) {
        char X = peek();
        char a = input[ip];

        if(X == '$' && a == '$') {
            printf("Parsing Successful!\n");
            return;
        }

        // Terminal
        if(X == '+' || X == '-' || X == '*' || X == '/' || X == '(' || X == ')' || X == 'i' || X == '$') {
            if(X == 'i' && isdigit(a)) { // match id
                pop();
                while(isdigit(input[ip])) ip++; // consume digits
            }
            else if(X == a) {
                pop(); ip++;
            }
            else error();
        }
        else { // Non-terminal, use table
            pop();
            // Table-driven logic
            if(X == 'E') {
                if(a == 'i' || a == '(') { push('E'); push('T'); } // simplified
            }
            // For a complete parser, we need full table expansion
        }
    }
}

int main() {
    printf("Enter input string ending with $ (e.g., id+id$):\n");
    scanf("%s", input);
    parse();
    return 0;
}
