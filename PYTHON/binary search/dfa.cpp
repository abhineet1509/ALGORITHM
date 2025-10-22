#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isIdentifier(char *str) {
    int i = 0;
    if (!isalpha(str[i]) && str[i] != '_') return 0;

    for (i = 1; str[i]; i++) {
        if (!isalnum(str[i]) && str[i] != '_') return 0;
    }
    return 1;
}

int isConstant(char *str) {
    int i = 0, hasDot = 0;

    if (str[i] == '+' || str[i] == '-') i++;

    for (; str[i]; i++) {
        if (str[i] == '.') {
            if (hasDot) return 0;  // multiple dots not allowed
            hasDot = 1;
        } else if (!isdigit(str[i])) {
            return 0;
        }
    }
    return (i > 0 && !(str[i - 1] == '.')); // should not end with dot
}

int isOperator(char *str) {
    const char *operators[] = {
        "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "%", NULL
    };
    for (int i = 0; operators[i]; i++) {
        if (strcmp(str, operators[i]) == 0) return 1;
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
        printf("Invalid Token\n");
    }

    return 0;
}