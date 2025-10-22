/* Operator-Precedence Parser in C for grammar:
   E -> E + E | E - E | E * E | E / E | ( E ) | id

   Terminals: +, -, *, /, (, ), id, $
   This version fixes previous pointer and stack issues.

   Compile: gcc -std=c99 -O2 -o op_parser operator_precedence_parser.c
   Run: ./op_parser "id + id * id"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOK 512
#define MAXSTACK 512

typedef struct { char type[16]; char lexeme[32]; } Token;

int tokenize(const char *s, Token tokens[], int *ntok) {
    int pos = 0; *ntok = 0;
    while (s[pos]) {
        if (isspace(s[pos])) { pos++; continue; }
        if (isalnum(s[pos])) {
            int start = pos;
            while (isalnum(s[pos])) pos++;
            int len = pos - start;
            strncpy(tokens[*ntok].lexeme, s+start, len); tokens[*ntok].lexeme[len] = '\0';
            strcpy(tokens[*ntok].type, "id");
            (*ntok)++;
        } else if (strchr("+-*/()", s[pos])) {
            tokens[*ntok].type[0] = s[pos]; tokens[*ntok].type[1] = '\0';
            tokens[*ntok].lexeme[0] = s[pos]; tokens[*ntok].lexeme[1] = '\0';
            (*ntok)++;
            pos++;
        } else {
            fprintf(stderr, "Unknown character: %c\n", s[pos]);
            return 0;
        }
    }
    strcpy(tokens[*ntok].type, "$" ); strcpy(tokens[*ntok].lexeme, "$" ); (*ntok)++;
    return 1;
}

const char *terms[] = {"+","-","*","/","(",")","id","$"};
char prec_table[8][8] = {
    {'>','>','<','<','<','>','<','>'}, // +
    {'>','>','<','<','<','>','<','>'}, // -
    {'>','>','>','>','<','>','<','>'}, // *
    {'>','>','>','>','<','>','<','>'}, // /
    {'<','<','<','<','<','=','<',' '}, // (
    {'>','>','>','>',' ','>',' ','>'}, // )
    {'>','>','>','>',' ','>',' ','>'}, // id
    {'<','<','<','<','<',' ','<','='}  // $
};

int index_of(const char *sym){
    for(int i=0;i<8;i++) if(strcmp(sym, terms[i])==0) return i;
    return -1;
}

int is_terminal(const char *sym){ return index_of(sym)>=0; }

typedef struct { const char *items[MAXSTACK]; int top; } Stack;
void push(Stack *s, const char *x){ s->items[s->top++] = x; }
const char *pop(Stack *s){ return s->items[--s->top]; }
const char *peek(Stack *s){ return s->items[s->top-1]; }

int op_prec_parse(Token tokens[], int ntok) {
    Stack st = {{0},0};
    push(&st, "$" );
    int ip=0;
    Token cur = tokens[ip];

    while (1) {
        int i = st.top-1;
        while (!is_terminal(st.items[i])) i--;
        const char *a = st.items[i];
        int row = index_of(a), col = index_of(cur.type);
        if (row<0 || col<0){ fprintf(stderr,"Invalid symbol in table\n"); return 0; }
        char rel = prec_table[row][col];

        if (rel=='<' || rel=='='){ // shift
            push(&st, cur.type);
            ip++; if(ip<ntok) cur = tokens[ip]; else { fprintf(stderr,"Unexpected end\n"); return 0; }
        } else if (rel=='>'){ // reduce
            // simple reduction: pop until top terminal has lower precedence
            do { pop(&st); i--; } while(i>=0 && prec_table[index_of(st.items[i])][col]=='>' );
        } else {
            fprintf(stderr,"Syntax error: stack top='%s', input='%s'\n", peek(&st), cur.type);
            return 0;
        }
        if(st.top==1 && strcmp(st.items[0], "$" )==0 && strcmp(cur.type, "$" )==0) break;
    }
    return 1;
}

int main(int argc, char **argv){
    Token tokens[MAXTOK]; int ntok;
    if(argc>1){
        char buf[256]={0};
        for(int i=1;i<argc;i++){ strcat(buf, argv[i]); strcat(buf," ");}
        if(!tokenize(buf, tokens, &ntok)) return 1;
        if(op_prec_parse(tokens, ntok)) printf("Input accepted.\n");
        else printf("Input rejected.\n");
        return 0;
    }
    printf("Usage: ./op_parser \"id + id * id\"\n");
    return 0;
}