 
%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%option yylineno
%option noyywrap

id [a-zA-Z_][a-zA-Z0-9_]*
entero [0-9]+
flotante [0-9]+("."[0-9]+)?([Ee][+-]?[0-9]+)?

%%

int {
        printf("int\n");
        return INT;
    }

float   {
            printf("float\n");
            return FLOAT;
        }

{id}    { 
            printf("id\n");
            return ID;
        }

{entero}    {   
                printf("entero\n");
                return NUM;
            }
            
{flotante}  {   
                printf("flotante\n");
                return NUM;
            }
            
"+" {
        printf("+\n");
        return MAS;
    }
    
"*" {
        printf("*\n");
        return MUL;
    }
    
"(" {
        printf("(\n");
        return LPAR;
    }
    
")" {
        printf(")\n");
        return RPAR;
    }
    
"=" {
        printf("=\n");
        return ASIG;
    }
    
"," {
        printf(",\n"); 
        return COMA;
    }
    
";" {
        printf(";\n");
        return PYC;
    }
    
[ \n\t]+ {}

. {printf("Error Léxico en la linea %d\n", yylineno);}

%%
    
