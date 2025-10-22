#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isIdentifier(char* str) {
    if (!(isalpha(str[0]) || str[0] == '_')) return 0;

    for (int i = 1; str[i]; i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) return 0;
    }
    return 1;
}

int isConstant(char* str) {
    int dot = 0;
    int i = 0;

    if (str[0] == '-' || str[0] == '+') i++; 

    for (; str[i]; i++) {
        if (str[i] == '.') {
            if (dot) return 0; 
            dot = 1;
        } else if (!isdigit(str[i])) return 0;
    }

    return (i > 0 && !(str[i-1] == '.'));
}

int isOperator(char* str) {
    const char* ops[] = {"+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", NULL};

    for (int i = 0; ops[i] != NULL; i++) {
        if (strcmp(str, ops[i]) == 0) return 1;
    }
    return 0;
}

int main() {
    char token[100];

    printf("Enter a token: ");
    scanf("%s", token);

    if (isIdentifier(token)) {
        printf("Identifier\n");
    } else if (isConstant(token)) {
        printf("Constant\n");
    } else if (isOperator(token)) {
        printf("Operator\n");
    } else {
        printf("Invalid token\n");
    }

    return 0;
}