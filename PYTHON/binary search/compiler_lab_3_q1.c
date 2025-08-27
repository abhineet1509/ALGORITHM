#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

char prod[MAX][MAX], first[MAX][MAX], follow[MAX][MAX];
int n;

int isNT(char c){ return isupper(c); }
void add(char *s,char c){ if(!strchr(s,c)){ int l=strlen(s); s[l]=c; s[l+1]=0; } }

void FIRST(char *res,char c){
    if(!isNT(c)){ add(res,c); return; }
    for(int i=0;i<n;i++) if(prod[i][0]==c){
        if(prod[i][3]=='#') add(res,'#'); else FIRST(res,prod[i][3]);
    }
}

void FOLLOW(char *res,char c){
    if(prod[0][0]==c) add(res,'$');
    for(int i=0;i<n;i++) for(int j=3;prod[i][j];j++) if(prod[i][j]==c){
        if(prod[i][j+1]){ char f[MAX]=""; FIRST(f,prod[i][j+1]); for(int k=0;f[k];k++) if(f[k]!='#') add(res,f[k]); }
        else if(prod[i][0]!=c) FOLLOW(res,prod[i][0]);
    }
}

void removeLeftRecursion(){
    printf("\nGrammar after removing Left Recursion:\n");
    for(int i=0;i<n;i++){
        char A=prod[i][0], alpha[MAX]="", beta[MAX]="";
        if(prod[i][3]==A){ strcpy(alpha,prod[i]+4); printf("%c->%c' \n",A,A); printf("%c'->%s%c'|#\n",A,alpha,A); }
        else printf("%s\n",prod[i]);
    }
}

int main(){
    printf("Enter number of productions: "); scanf("%d",&n);
    printf("Enter productions (E->E+T or E->T):\n");
    for(int i=0;i<n;i++) scanf("%s",prod[i]);

    removeLeftRecursion();

    for(int i=0;i<n;i++){ char f[MAX]="",fo[MAX]=""; FIRST(f,prod[i][0]); FOLLOW(fo,prod[i][0]); strcpy(first[i],f); strcpy(follow[i],fo);}
    printf("\n--- FIRST & FOLLOW Sets ---\n");
    for(int i=0;i<n;i++) printf("FIRST(%c)={%s}, FOLLOW(%c)={%s}\n",prod[i][0],first[i],prod[i][0],follow[i]);
}
