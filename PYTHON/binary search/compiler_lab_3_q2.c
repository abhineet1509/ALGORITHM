#include <stdio.h>
#include <string.h>
#define MAX 20

char prod[MAX][MAX]; int n;

int isNT(char c){ return c>='A' && c<='Z'; }

void add(char *res,char c){
    if(!strchr(res,c)){ int l=strlen(res); res[l]=c; res[l+1]='\0'; }
}

void FIRST(char *res,char c){
    if(!isNT(c)){ add(res,c); return; }
    for(int i=0;i<n;i++) if(prod[i][0]==c){
        if(prod[i][3]=='#') add(res,'#');
        else{
            for(int j=3; prod[i][j]; j++){
                char temp[20]=""; FIRST(temp,prod[i][j]);
                for(int k=0; temp[k]; k++) if(temp[k]!='#') add(res,temp[k]);
                if(!strchr(temp,'#')) break;
                if(!prod[i][j+1]) add(res,'#');
            }
        }
    }
}

void FOLLOW(char *res,char c){
    if(c==prod[0][0]) add(res,'$');
    for(int i=0;i<n;i++)
        for(int j=3; prod[i][j]; j++) if(prod[i][j]==c){
            if(prod[i][j+1]){
                char temp[20]=""; FIRST(temp,prod[i][j+1]);
                for(int k=0; temp[k]; k++) if(temp[k]!='#') add(res,temp[k]);
                if(strchr(temp,'#')) FOLLOW(res,prod[i][0]);
            } else if(prod[i][0]!=c) FOLLOW(res,prod[i][0]);
        }
}

void leftFactor(char *p){
    char A=p[0]; char *q=strchr(p,'|'); if(!q) return;
    char *r1=p+3,*r2=q+1; int i=0;
    while(r1[i]&&r2[i]&&r1[i]==r2[i]) i++;
    if(i>0){
        printf("%c -> %.*s%c'\n",A,i,r1,A);
        printf("%c' -> %s | %s\n",A,r1+i,r2+i);
    }
}

int main(){
    printf("No. of productions: "); scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",prod[i]);

    printf("\nAfter Left Factoring:\n");
    for(int i=0;i<n;i++) leftFactor(prod[i]);

    for(int i=0;i<n;i++){
        char f[20]="", fo[20]="";
        FIRST(f,prod[i][0]); FOLLOW(fo,prod[i][0]);
        printf("FIRST(%c)={%s}  FOLLOW(%c)={%s}\n",prod[i][0],f,prod[i][0],fo);
    }
}
