#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

// Grammar:
// S' → S
// S → AB
// A → aA | a
// B → bB | b

// Function to check if string is accepted
int parseLALR(char input[]) {
    int i, j, k;
    char stack[MAX];
    int top = 0;
    stack[top] = '$';
    i = 0;
    input[strlen(input)] = '$';
    input[strlen(input) + 1] = '\0';

    printf("\nStack\t\tInput\t\tAction\n");
    printf("--------------------------------------\n");

    while (1) {
        printf("%s\t\t%s\t\t", stack, &input[i]);

        // Accept condition
        if (stack[top] == 'S' && input[i] == '$') {
            printf("Accept\n");
            return 1;
        }

        // Shift
        if (input[i] == 'a' || input[i] == 'b') {
            top++;
            stack[top] = input[i];
            i++;
            printf("Shift\n");
        }

        // Reduce operations according to grammar
        else {
            // Reduce A -> a
            if (stack[top] == 'a') {
                stack[top] = 'A';
                printf("Reduce A->a\n");
            }

            // Reduce A -> aA
            else if (top >= 1 && stack[top] == 'A' && stack[top - 1] == 'a') {
                top--;
                stack[top] = 'A';
                printf("Reduce A->aA\n");
            }

            // Reduce B -> b
            else if (stack[top] == 'b') {
                stack[top] = 'B';
                printf("Reduce B->b\n");
            }

            // Reduce B -> bB
            else if (top >= 1 && stack[top] == 'B' && stack[top - 1] == 'b') {
                top--;
                stack[top] = 'B';
                printf("Reduce B->bB\n");
            }

            // Reduce S -> AB
            else if (top >= 1 && stack[top] == 'B' && stack[top - 1] == 'A') {
                top--;
                stack[top] = 'S';
                printf("Reduce S->AB\n");
            }

            else {
                printf("Error\n");
                return 0;
            }
        }
    }
}

int main() {
    char input[MAX];
    printf("Enter input string (like aabb, aaabbb, ab): ");
    scanf("%s", input);

    if (parseLALR(input))
        printf("\nString Accepted by LALR Parser!\n");
    else
        printf("\nString Rejected by LALR Parser!\n");

    return 0;
}
