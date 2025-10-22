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
    printf("Enter the input string (use a/b as operands): ");
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

            // Reduce a -> E
            if (top >= 0 && stack[top] == 'a') {
                pop_n(1);
                push('E');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE E->a", stack, input + ip);
                reduced = 1;
            }

            // Reduce b -> E
            else if (top >= 0 && stack[top] == 'b') {
                pop_n(1);
                push('E');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE E->b", stack, input + ip);
                reduced = 1;
            }

            // Reduce E+E -> E
            else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
                pop_n(3);
                push('E');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE E->E+E", stack, input + ip);
                reduced = 1;
            }

            // Reduce E/E -> E
            else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '/' && stack[top - 2] == 'E') {
                pop_n(3);
                push('E');
                printf("\nStack: %s\tInput: %s\tAction: REDUCE E->E/E", stack, input + ip);
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

    // Final check
    if (strcmp(stack, "E") == 0)
        printf("\n\nString accepted (Valid Expression)\n");
    else
        printf("\n\nString rejected (Parsing failed)\n");

    return 0;
}
