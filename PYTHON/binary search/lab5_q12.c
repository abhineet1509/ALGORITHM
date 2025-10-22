#include <stdio.h>
#include <string.h>

#define MAX 50

char stack[MAX];       // stack to hold symbols
int top = -1;          // stack top
char input[MAX];       // input string

// Function to push a symbol onto stack
void push(char c) {
    stack[++top] = c;
}

// Function to pop a symbol from stack
char pop() {
    if(top == -1) return '\0';
    return stack[top--];
}

// Function to display stack
void display_stack() {
    for(int i = 0; i <= top; i++)
        printf("%c", stack[i]);
}

// Function to perform reduction
int reduce() {
    // Check for E+E
    if(top >= 2 && stack[top-2] == 'E' && stack[top-1] == '+' && stack[top] == 'E') {
        top -= 2;
        stack[top] = 'E';
        printf("\nReduced: E -> E+E");
        return 1;
    }
    // Check for E*E
    if(top >= 2 && stack[top-2] == 'E' && stack[top-1] == '*' && stack[top] == 'E') {
        top -= 2;
        stack[top] = 'E';
        printf("\nReduced: E -> E*E");
        return 1;
    }
    // Check for E/E
    if(top >= 2 && stack[top-2] == 'E' && stack[top-1] == '/' && stack[top] == 'E') {
        top -= 2;
        stack[top] = 'E';
        printf("\nReduced: E -> E/E");
        return 1;
    }
    // Check for E -> a
    if(stack[top] == 'a') {
        stack[top] = 'E';
        printf("\nReduced: E -> a");
        return 1;
    }
    // Check for E -> b
    if(stack[top] == 'b') {
        stack[top] = 'E';
        printf("\nReduced: E -> b");
        return 1;
    }

    return 0; // No reduction possible
}

int main() {
    printf("Enter input string (e.g., a+b): ");
    scanf("%s", input);

    int i = 0;
    printf("\nStack\t\tInput\t\tAction\n");
    printf("----------------------------------------\n");

    while(input[i] != '\0') {
        // Shift
        push(input[i]);
        printf("%-16s%-16sShift %c\n", stack, input + i, input[i]);
        i++;

        // Try reducing as much as possible
        while(reduce());
    }

    // Final reductions after input is consumed
    while(reduce());

    if(top == 0 && stack[top] == 'E') {
        printf("\nInput string is VALID.\n");
    } else {
        printf("\nInput string is INVALID.\n");
    }

    return 0;
}
