
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char prod[MAX][MAX];
int n;

void add(char set[], char c) {
    int i; for (i=0; set[i]; i++) if (set[i]==c) return;
    set[i]=c; set[i+1]='\0';
}

void first(char res[], char c) {
    if (!isupper(c)) { add(res,c); return; }
    for (int i=0;i<n;i++) if (prod[i][0]==c) {
        if (prod[i][2]=='$') add(res,'$');
        else first(res,prod[i][2]);
    }
}

void follow(char res[], char c) {
    if (prod[0][0]==c) add(res,'$'); // start symbol
    for (int i=0;i<n;i++)
      for (int j=2;j<strlen(prod[i]);j++)
        if (prod[i][j]==c) {
            if (prod[i][j+1]) first(res,prod[i][j+1]);
            else if (prod[i][0]!=c) follow(res,prod[i][0]);
        }
}

void removeLeftRec() {
    printf("\nAfter removing Left Recursion:\n");
    for (int i=0;i<n;i++) {
        char A=prod[i][0];
        if (prod[i][0]==prod[i][2]) {
            printf("%c=%c'%s\n",A,A,prod[i]+3);
            printf("%c'=%s%c'|ε\n",A,prod[i]+3,A);
        } else printf("%s\n",prod[i]);
    }
}

int main() {
    char res[20];
    printf("Enter number of productions: "); scanf("%d",&n);
    printf("Enter productions (A=aB form, use $ for ε):\n");
    for (int i=0;i<n;i++) scanf("%s",prod[i]);

    removeLeftRec();

    printf("\nFIRST & FOLLOW:\n");
    for (int i=0;i<n;i++) {
        res[0]='\0'; first(res,prod[i][0]);
        printf("FIRST(%c)={%s}\n",prod[i][0],res);
        res[0]='\0'; follow(res,prod[i][0]);
        printf("FOLLOW(%c)={%s}\n",prod[i][0],res);
    }
}