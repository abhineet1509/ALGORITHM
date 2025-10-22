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
    printf("Enter input string (use i as operand, e.g., i+i*i): ");
    scanf("%s", input);

    int ip = 0;
    printf("\nSHIFT-REDUCE PARSING\n");

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

            // Reduce i -> E
            if (top >= 0 && stack[top] == 'i') {
                pop_n(1);
                push('E');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE E->i", stack, input + ip);
                reduced = 1;
            }

            // Reduce E+E -> E
            else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
                pop_n(3);
                push('E');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE E->E+E", stack, input + ip);
                reduced = 1;
            }

            // Reduce E*E -> E
            else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
                pop_n(3);
                push('E');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE E->E*E", stack, input + ip);
                reduced = 1;
            }
        }

        if (ip >= strlen(input)) break;
    }

    // Final reduction (if possible)
    int final_reduce = 1;
    while (final_reduce) {
        final_reduce = 0;
        if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
            pop_n(3);
            push('E');
            final_reduce = 1;
        } else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
            pop_n(3);
            push('E');
            final_reduce = 1;
        }
    }

    // Check final stack
    printf("\nFinal Stack: %s\n", stack);
    if (strcmp(stack, "E") == 0)
        printf("Input string is VALID\n");
    else
        printf("Input string is INVALID\n");

    return 0;
}
