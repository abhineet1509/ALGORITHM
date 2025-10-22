#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Productions
// 1. S' -> S
// 2. S  -> A B
// 3. A  -> a A
// 4. A  -> a
// 5. B  -> b B
// 6. B  -> b

// ACTION and GOTO tables (manually created for this grammar)
char *action[12][3]; // columns: a, b, $
int goTo[12][4];     // columns: S, A, B

void initialize() {
    // Initialize ACTION table
    action[0][0] = "s3";  // (0, a)
    action[1][2] = "acc"; // (1, $)
    action[2][1] = "s6";  // (2, b)
    action[3][0] = "s3";  // (3, a)
    action[3][1] = "r4";  // (3, b)
    action[3][2] = "r4";  // (3, $)
    action[4][1] = "s6";  // (4, b)
    action[4][2] = "r2";  // (4, $)
    action[5][1] = "r1";  // (5, b)
    action[5][2] = "r1";  // (5, $)
    action[6][1] = "s6";  // (6, b)
    action[6][2] = "r6";  // (6, $)
    action[7][1] = "r5";  // (7, b)
    action[7][2] = "r5";  // (7, $)

    // Initialize GOTO table
    goTo[0][0] = 1; // S
    goTo[0][1] = 2; // A
    goTo[2][2] = 5; // B
    goTo[3][1] = 4; // A
    goTo[6][2] = 7; // B
}

char input[MAX];
int stack[MAX];
char symbol[MAX];
int top = 0;

void pushState(int s) {
    stack[++top] = s;
}

int popState() {
    return stack[top--];
}

void printStack(int top, char *input, int i, char *actionStr) {
    printf("\n");
    printf("Stack: ");
    for (int j = 0; j <= top; j++) printf("%d ", stack[j]);
    printf("\tInput: %s\tAction: %s", &input[i], actionStr);
}

void reduce(int rule) {
    switch (rule) {
        case 1: printf(" Reduce by S -> A B"); break;
        case 2: printf(" Reduce by A -> a A"); break;
        case 3: printf(" Reduce by A -> a"); break;
        case 4: printf(" Reduce by B -> b B"); break;
        case 5: printf(" Reduce by B -> b"); break;
    }
}

int main() {
    initialize();

    printf("Enter input string (a's followed by b's): ");
    scanf("%s", input);
    strcat(input, "$");

    int i = 0;
    top = 0;
    stack[top] = 0;

    printf("\n---------------------------------------------");
    printf("\nStack\t\tInput\t\tAction");
    printf("\n---------------------------------------------");

    while (1) {
        int state = stack[top];
        char current = input[i];
        int col;

        if (current == 'a') col = 0;
        else if (current == 'b') col = 1;
        else col = 2;

        char *act = action[state][col];

        if (act == NULL) {
            printf("\nError: Invalid input or state transition.\n");
            break;
        }

        if (strcmp(act, "acc") == 0) {
            printStack(top, input, i, "Accept");
            printf("\n---------------------------------------------");
            printf("\nString Accepted.\n");
            break;
        }

        printStack(top, input, i, act);

        if (act[0] == 's') {
            // Shift
            int newState = atoi(&act[1]);
            pushState(newState);
            i++;
        } else if (act[0] == 'r') {
            // Reduce
            int rule = atoi(&act[1]);
            int popCount;
            char lhs;

            switch (rule) {
                case 1: popCount = 4; lhs = 'S'; break; // A B
                case 2: popCount = 4; lhs = 'A'; break; // a A
                case 3: popCount = 2; lhs = 'A'; break; // a
                case 4: popCount = 4; lhs = 'B'; break; // b B
                case 5: popCount = 2; lhs = 'B'; break; // b
                default: popCount = 0; lhs = ' '; break;
            }

            for (int k = 0; k < popCount / 2; k++) popState();

            state = stack[top];
            int newState;

            if (lhs == 'S') newState = goTo[state][0];
            else if (lhs == 'A') newState = goTo[state][1];
            else newState = goTo[state][2];

            pushState(newState);
            reduce(rule);
        }
    }
    return 0;
}
