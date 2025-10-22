#include <stdio.h>
#include <string.h>

#define MAX 100

char input[MAX];
int index_ptr = 0;

// --- Utility ---
char peek() {
    return input[index_ptr];
}

int consume(char expected) {
    if (peek() == expected) {
        index_ptr++;
        return 1;
    }
    return 0;
}

void reset(int pos) {
    index_ptr = pos;
}

// --- Parser Functions ---
int parseS();
int parseA();

int parseS() {
    int saved = index_ptr;
    if (consume('c')) {
        if (parseA()) {
            if (consume('d')) {
                return 1;
            }
        }
    }
    reset(saved);
    return 0;
}

int parseA() {
    int saved = index_ptr;
    
    // First production: A → ab
    if (consume('a')) {
        if (consume('b')) {
            return 1;
        }
        // backtrack if 'b' not found
        reset(saved);
    }
    
    // Second production: A → a
    if (consume('a')) {
        return 1;
    }
    
    reset(saved);
    return 0;
}

// --- Main Function ---
int main() {
    printf("Enter input string: ");
    scanf("%s", input);

    if (parseS() && input[index_ptr] == '\0') {
        printf("Parsing Successful!\n");
    } else {
        printf("Parsing Failed!\n");
    }

    return 0;
}
