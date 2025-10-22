#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop_n(int n) {
    top -= n;
    stack[top + 1] = '\0';
}

void print_stack_input(const char *input, int ip) {
    printf("\nStack: %s\tInput: %s\tAction: ", stack, input + ip);
}

int main() {
    char input[100];
    printf("Enter input string (use 'char' for operands, e.g., char+char*char): ");
    scanf("%s", input);

    int ip = 0;
    printf("\nLR(0) PARSING (SHIFT-REDUCE SIMULATION)\n");

    while (1) {
        print_stack_input(input, ip);

        // SHIFT
        if (ip < strlen(input)) {
            printf("SHIFT");
            push(input[ip]);
            ip++;
        }

        // REDUCE
        int reduced = 1;
        while (reduced) {
            reduced = 0;

            // Reduce char -> F
            if (top >= 0 && stack[top] == 'c') {  // using 'c' for char
                pop_n(1);
                push('F');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE F->char", stack, input + ip);
                reduced = 1;
            }

            // Reduce (E) -> F
            else if (top >= 2 && stack[top-2] == '(' && stack[top-1] == 'E' && stack[top] == ')') {
                pop_n(3);
                push('F');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE F->(E)", stack, input + ip);
                reduced = 1;
            }

            // Reduce T*F -> T
            else if (top >= 2 && stack[top-2] == 'T' && stack[top-1] == '*' && stack[top] == 'F') {
                pop_n(3);
                push('T');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE T->T*F", stack, input + ip);
                reduced = 1;
            }

            // Reduce F -> T
            else if (top >= 0 && stack[top] == 'F') {
                pop_n(1);
                push('T');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE T->F", stack, input + ip);
                reduced = 1;
            }

            // Reduce E+T -> E
            else if (top >= 2 && stack[top-2] == 'E' && stack[top-1] == '+' && stack[top] == 'T') {
                pop_n(3);
                push('E');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE E->E+T", stack, input + ip);
                reduced = 1;
            }
        }

        if (ip >= strlen(input)) break;
    }

    // Final reductions if possible
    int final_reduce = 1;
    while (final_reduce) {
        final_reduce = 0;
        if (top >= 2 && stack[top-2] == 'E' && stack[top-1] == '+' && stack[top] == 'T') {
            pop_n(3);
            push('E');
            final_reduce = 1;
        } else if (top >= 2 && stack[top-2] == 'T' && stack[top-1] == '*' && stack[top] == 'F') {
            pop_n(3);
            push('T');
            final_reduce = 1;
        } else if (top >= 0 && stack[top] == 'F') {
            pop_n(1);
            push('T');
            final_reduce = 1;
        }
    }

    printf("\nFinal Stack: %s\n", stack);
    if (strcmp(stack, "E") == 0)
        printf("Input string is VALID\n");
    else
        printf("Input string is INVALID\n");

    return 0;
}
