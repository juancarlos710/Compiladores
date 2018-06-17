%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE* yyin;
extern int yylex();

void yyerror(char* s);
%} 



%token ID
%token NUM;
%token COMA PYC
%token INT FLOAT
%left MAS
%left MUL
%left ASIG
%nonassoc LPAR RPAR

%start program


%%
program : decl sents {printf("Se realizo correctamente el análisis\n");} ;

decl: decl type list PYC{printf("D-> D T L;\n");} | {printf("D->3\n");};

type: INT{printf("T->int\n");} | FLOAT{printf("T->float\n");};

list : list COMA ID {printf("L->L,id\n");}| ID{printf("L->id\n");};

sents: sents sent {printf("S->S I\n");}
    | sent{printf("S->I\n");};
    
sent:  ID ASIG expresion PYC{printf("I->id= E;\n");};
    
expresion : expresion MAS expresion {printf("E->E+E\n");}
    | expresion MUL expresion{printf("E->E*E\n");}
    | LPAR expresion RPAR{printf("E->(E)\n");}
    | ID{printf("E->id\n");}
    | NUM{printf("E->num\n");};
    
%%

void yyerror(char *s){
    printf("Error: %s\n",s);
}

int main(int argc, char** argv){
    FILE* file;
    if(argc >1){
        file = fopen(argv[1], "r");
        if(file==NULL){
            printf("no existe el fichero %s\n", argv[1]);
            exit(1);
        }
        
        printf("se abrio el archivo\n");
        yyin = file;
        yyparse();
    }
    
    return 1;
}
