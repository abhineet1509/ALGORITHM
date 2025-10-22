// slr_parser.c
// Simple shift-reduce (SLR-style) demo for grammar:
// E -> E + T | T
// T -> T * F | F
// F -> ( E ) | i
// Use 'i' to denote identifier (id)

#include <stdio.h>
#include <string.h>

#define MAX 200

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX-1) stack[++top] = c;
}
void popn(int n) {
    if (n <= top+1) top -= n;
}
void displayStack() {
    if (top < 0) printf("ε");
    else {
        for (int i = 0; i <= top; ++i) putchar(stack[i]);
    }
}

struct prod { char lhs; const char *rhs; };
struct prod prods[] = {
    {'E', "E+T"},
    {'E', "T"},
    {'T', "T*F"},
    {'T', "F"},
    {'F', "(E)"},
    {'F', "i"}
};
int nprods = sizeof(prods)/sizeof(prods[0]);

// Try to reduce once. If reduced, print which production and return 1.
// Otherwise return 0.
int try_reduce() {
    for (int p = 0; p < nprods; ++p) {
        int rlen = (int)strlen(prods[p].rhs);
        if (top + 1 < rlen) continue;
        int match = 1;
        for (int j = 0; j < rlen; ++j) {
            if (stack[top - rlen + 1 + j] != prods[p].rhs[j]) { match = 0; break; }
        }
        if (match) {
            // perform reduction: pop rhs and push lhs
            popn(rlen);
            push(prods[p].lhs);
            printf("Reduce by %c -> %s\n", prods[p].lhs, prods[p].rhs);
            return 1;
        }
    }
    return 0;
}

int main() {
    char input[MAX];
    printf("Enter input string (use 'i' for id, e.g. i+i*i): ");
    if (scanf("%s", input) != 1) return 0;

    int ip = 0; // input pointer

    printf("\nStack\t\tInput\t\tAction\n");
    printf("--------------------------------------------------\n");

    while (1) {
        // Print current stack and remaining input
        displayStack();
        printf("\t\t%s\t", input + ip);

        // First try to reduce (if possible)
        if (try_reduce()) {
            // try_reduce prints reduction info already
            continue; // after reduce, try reduce again in next iteration
        }

        // If no reduction possible, try shifting next input symbol (if any)
        if (input[ip] != '\0') {
            printf("Shift '%c'\n", input[ip]);
            push(input[ip]);
            ip++;
            continue;
        }

        // input exhausted and no reduction possible -> break
        printf("No more shifts, no reduction possible\n");
        break;
    }

    // After main loop, try reducing as much as possible
    while (try_reduce()) { /* keep reducing */ }

    // Final state
    printf("Final stack: ");
    displayStack();
    printf("\n");

    if (top == 0 && stack[0] == 'E' && input[ip] == '\0') {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed!\n");
    }
    return 0;
}
