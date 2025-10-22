#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int main() {
    char input[MAX];
    printf("Enter input string: ");
    scanf("%s", input);

    // Add end marker
    strcat(input, "$");

    // Initialize stack with start symbol and end marker
    push('$');
    push('S');

    int i = 0; // input pointer

    while (top >= 0) {
        char X = peek();
        char a = input[i];

        // If top of stack is terminal or $
        if (X == a && X == '$') {
            printf("Parsing Successful!\n");
            return 0;
        } else if (X == a) {
            pop(); // match terminal
            i++;
        } 
        else if (X == 'S') {
            pop();
            if (a == 'a') {
                // S → AaAb
                // Push in reverse order: b A a A
                push('b');
                push('A');
                push('a');
                push('A');
            } else if (a == 'b') {
                // S → BbBa
                // Push in reverse order: a B b B
                push('a');
                push('B');
                push('b');
                push('B');
            } else {
                printf("Parsing Failed!\n");
                return 0;
            }
        } 
        else if (X == 'A') {
            // A → ε (pop A)
            pop();
        } 
        else if (X == 'B') {
            // B → ε (pop B)
            pop();
        } 
        else {
            printf("Parsing Failed!\n");
            return 0;
        }
    }

    if (input[i] == '$') {
        printf("Parsing Successful!\n");
    } else {
        printf("Parsing Failed!\n");
    }

    return 0;
}
