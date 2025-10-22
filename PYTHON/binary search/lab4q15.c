#include <stdio.h>
#include <string.h>

char input[100];
int ip = 0;  // input pointer

// Function declarations
void E();
void Eprime();
void T();
void Tprime();
void F();

// Match current input symbol with expected terminal
void match(char x) {
    if (input[ip] == x) {
        printf("Matched: %c\n", x);
        ip++;
    } else {
        printf("Error: expected '%c', found '%c'\n", x, input[ip]);
        exit(1);
    }
}

// E -> T E'
void E() {
    T();
    Eprime();
}

// E' -> + T E' | ε
void Eprime() {
    if (input[ip] == '+') {
        match('+');
        T();
        Eprime();
    }
    // else epsilon, do nothing
}

// T -> F T'
void T() {
    F();
    Tprime();
}

// T' -> * F T' | ε
void Tprime() {
    if (input[ip] == '*') {
        match('*');
        F();
        Tprime();
    }
    // else epsilon, do nothing
}

// F -> ( E ) | id
void F() {
    if (input[ip] == '(') {
        match('(');
        E();
        match(')');
    } else if (input[ip] == 'i') {
        match('i');  // id is represented by 'i'
    } else {
        printf("Error: unexpected symbol '%c'\n", input[ip]);
        exit(1);
    }
}

int main() {
    printf("Enter input string (use 'i' for id, e.g., i+i*i): ");
    scanf("%s", input);

    E();

    if (input[ip] == '\0') {
        printf("Parsing Successful! Input is valid.\n");
    } else {
        printf("Parsing Failed! Unconsumed input remains.\n");
    }

    return 0;
}
