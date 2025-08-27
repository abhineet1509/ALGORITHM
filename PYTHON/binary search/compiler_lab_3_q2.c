
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char prod[MAX][MAX];
int n;

int isNT(char c){ return isupper(c); }

void add(char *set,char c){
    if(!strchr(set,c)){ int l=strlen(set); set[l]=c; set[l+1]='\0'; }
}

void FIRST(char *res,char c){
    if(!isNT(c)){ add(res,c); return; }
    for(int i=0;i<n;i++) if(prod[i][0]==c){
        if(prod[i][3]=='#') add(res,'#');
        else FIRST(res,prod[i][3]);
    }
}

void FOLLOW(char *res,char c){
    if(prod[0][0]==c) add(res,'$');
    for(int i=0;i<n;i++){
        for(int j=3;prod[i][j];j++) if(prod[i][j]==c){
            if(prod[i][j+1]){ char f[MAX]=""; FIRST(f,prod[i][j+1]);
                for(int k=0;f[k];k++) if(f[k]!='#') add(res,f[k]);
            } else if(prod[i][0]!=c) FOLLOW(res,prod[i][0]);
        }
    }
}

// ----- Remove Left Factoring -----
void leftFactor(){
    printf("\nAfter Left Factoring:\n");
    char newP[MAX][MAX]; int cnt=0;
    for(int i=0;i<n;i++){
        char A=prod[i][0], *rhs=prod[i]+3;
        char *alt1=strtok(rhs,"|"), *alt2=strtok(NULL,"|");
        if(alt2 && alt1[0]==alt2[0]){ // common prefix
            printf("%c->%c%c'\n",A,alt1[0],A);
            printf("%c'->%s|%s\n",A,alt1+1,alt2+1);
            sprintf(newP[cnt++],"%c->%c%c'",A,alt1[0],A);
            sprintf(newP[cnt++],"%c'->%s|%s",A,alt1+1,alt2+1);
        } else strcpy(newP[cnt++],prod[i]);
    }
    n=cnt; for(int i=0;i<n;i++) strcpy(prod[i],newP[i]);
}

int main(){
    printf("Enter no. of productions: "); scanf("%d",&n);
    printf("Enter productions (e.g., E->aA|aB):\n");
    for(int i=0;i<n;i++) scanf("%s",prod[i]);

    leftFactor();

    printf("\n--- FIRST & FOLLOW ---\n");
    for(int i=0;i<n;i++){
        char f[MAX]="", fo[MAX]="";
        FIRST(f,prod[i][0]); FOLLOW(fo,prod[i][0]);
        printf("FIRST(%c)={%s}, FOLLOW(%c)={%s}\n",
               prod[i][0],f,prod[i][0],fo);
    }
}
