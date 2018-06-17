 
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
        //printf("int\n");
        return INT;
    }

float   {
            //printf("float\n");
            return FLOAT;
        }

{id}    { 
            //printf("id\n");
            yylval.line = yylineno;            
            strcpy(yylval.sval, yytext);
            //printf("se hizo la copia \n");
            return ID;
        }

{entero}    {   
                //printf("entero\n");
                yylval.line = yylineno;
                yylval.num.tipo = 1;                
                strcpy(yylval.num.sval, yytext);
                yylval.num.ival = atoi(yytext);
                return NUM;
            }
            
{flotante}  {   
                //printf("flotante\n");
                yylval.line = yylineno;
                yylval.num.tipo = 2;                
                strcpy(yylval.num.sval, yytext);
                yylval.num.dval = atof(yytext);
                return NUM;
            }
            
"+" {
        //printf("+\n");
        return MAS;
    }
    
"*" {
        //printf("*\n");
        return MUL;
    }
    
"(" {
        //printf("(\n");
        return LPAR;
    }
    
")" {
        //printf(")\n");
        return RPAR;
    }
    
"=" {
        //printf("=\n");
        return ASIG;
    }
    
"," {
        //printf(",\n"); 
        return COMA;
    }
    
";" {
        ///printf(";\n");
        return PYC;
    }

"[" {
	return LCOR;
    }

"]" {
	return RCOR;
   }
    
[ \n\t]+ {}

. {printf("Error Léxico en la linea %d\n", yylineno);}

%%
    
