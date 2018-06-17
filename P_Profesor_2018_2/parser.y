%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

int dir;
/*pila pilaNext;
pila pilaTrue;
pila pilaFalse;*/

struct{
    char id[32];
    int dir;
    int tipo;
    int var;
} tabla_simbolos[100];

int contador_sim=0;

int tipo;
int dim;

extern int yylex();
extern FILE *yyin;
extern int yylineno;

void yyerror(char *msg);
void init();
void imprimir();
int insertar(char *id, int dir, int tipo, int var);
%}


%union{
    struct{
        union{
            int ival;
            double dval;
        }valor;
        int tipo;
    }numero;
    
    char id[32];
    
    struct{
        char dir[32];
        int tipo;
    }expresion;
    
    struct{
        int tipo;
        int dimension;
    }type;
}

%token IF ELSE WHILE DO INT FLOAT
%token LKEY RKEY PYC COMA
%token<id> ID
%token<numero> NUM

%right ASIG
%left OR
%left AND
%left EQ NE
%left LT GT GTE LTE
%left MAS
%left MUL
%left NOT
%nonassoc LPAR RPAR
%left IFX

%start program

%type<expresion> exp
%type<type> tipo

%%

program : {init();} decl {imprimir(); pushNext(newLabel());} sent;

decl : tipo {tipo = $1.tipo; 
             dim = $1.dimension;} lista_var PYC decl | ;

tipo: INT { $$.tipo = 0; $$.dimension = 4;}
       | FLOAT { $$.tipo = 1; $$.dimension = 4;};
       
lista_var : lista_var COMA ID {
                        if(insertar($3, dir, tipo, 0)==-1)
                            yyerror("ID duplicado");                                  
                        else
                            dir += dim;
            }
            
            | ID{
                        if(insertar($1, dir, tipo, 0)==-1)
                            yyerror("ID duplicado");                                  
                        else
                            dir += dim;
            };
            
            
sent: {pushNext(newLabel());}sent{popNext();} sent
    | ID ASIG exp PYC
    | IF LPAR boolean RPAR sent 
    | IF LPAR boolean RPAR sent ELSE sent %prec IFX;
    
exp: ID {   
            strcpy($$.dir, $1); 
            $$.tipo= getTipo($1);
            if($$.tipo == -1){
                yyerror("La variable no fue declarada");
            }
        } 
    | NUM{
            $$.tipo = $1.tipo;
            if($$.tipo == 0){
                sprintf($$.dir, "%d", $1.valor.ival);
            else 
                sprintf($$.dir,"%lf", $1.valor.dval);
    };


boolean: boolean OR boolean 
        | boolean AND boolean
        | NOT boolean
        | exp relacional exp;
        
relacional : LT | GT;
    

            
%%

void yyerror(char *msg){
    printf("%s, %d\n", msg, yylineno);
}

int getTipo(char *id, int dir, int tipo, int var){
    for(int i = 0; i < contador_sim; i++){
        if(strcmp(id,tabla_simbolos[i].id)==0)
            return tabla_simbolos[i].tipo;
    }
    return -1;
}

int insertar(char *id, int dir, int tipo, int var){
    for(int i = 0; i < contador_sim; i++){
        if(strcmp(id,tabla_simbolos[i].id)==0)
            return -1;
    }
    strcpy(tabla_simbolos[contador_sim].id,id);
    tabla_simbolos[contador_sim].dir = dir;
    tabla_simbolos[contador_sim].tipo = tipo;
    tabla_simbolos[contador_sim].var = var;
    contador_sim++;
    return 0;
}

void imprimir(){
    printf("ID\tDIR\tTIPO\tVAR\n");
    for(int i = 0; i < contador_sim; i++){
        printf("%s\t%d\t%d\t%d\n",tabla_simbolos[i].id,
                tabla_simbolos[i].dir,
                tabla_simbolos[i].tipo,
                tabla_simbolos[i].var);
 
    }
}

void init(){}


int  main(int argc, char **argv){
    FILE *f;
    if(argc < 2)
        exit(0);
    
    f = fopen(argv[1], "r");
    if(!f)
        exit(1);
    
    yyin= f;
    
    yyparse();
    
    fclose(yyin);
    return 0;
}
