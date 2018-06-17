 
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
flotante [0-9]+("."[0-9]+)?([Ee][+-]?[0-9]+)?[fF]
doble [0-9]+("."[0-9]+)?([Ee][+-]?[0-9]+)?

%%

void    {  
            yylval.line = yylineno;
            return VOID;
        }
        
char    {
            yylval.line = yylineno;
            return CHAR;
        }
        
int {
        //printf("int\n");
        yylval.line = yylineno;
        return INT;
    }

float   {
            //printf("float\n");
            yylval.line = yylineno;
            return FLOAT;
        }
        
double  {
            yylval.line = yylineno;
            return DOUBLE;
        }
        
struct  {
            yylval.line = yylineno;
            return STRUCT;
        }

define {
            yylval.line = yylineno;
            return DEFINE;
        }
        
return {
            yylval.line = yylineno;
            return RETURN;
        }
        
if {
            yylval.line = yylineno;
            return IF;
        }
        
"true" {
            yylval.line = yylineno;
            return TRUE;
        }
   
"false" {
            yylval.line = yylineno;
            return FALSE;
        }
    
"while" {
            yylval.line = yylineno;
            return WHILE;
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
                yylval.num.tipo = 2;                
                strcpy(yylval.num.sval, yytext);
                yylval.num.ival = atoi(yytext);
                return NUM;
            }

{doble}  {   
                //printf("flotante\n");
                yylval.line = yylineno;
                yylval.num.tipo = 4;                
                strcpy(yylval.num.sval, yytext);
                yylval.num.dval = atof(yytext);
                return NUM;
            }
            
{flotante}  {   
                //printf("flotante\n");
                yylval.line = yylineno;
                yylval.num.tipo = 3;                
                strcpy(yylval.num.sval, yytext);
                yylval.num.dval = atof(yytext);
                return NUM;
            }
            
"+" {
        //printf("+\n");
        yylval.line = yylineno;
        return MAS;
    }
    
"*" {
        //printf("*\n");
        yylval.line = yylineno;
        return MUL;
    }
    
"(" {
        //printf("(\n");
        yylval.line = yylineno;
        return LPAR;
    }
    
")" {
        //printf(")\n");
        yylval.line = yylineno;
        return RPAR;
    }
    
"=" {
        //printf("=\n");
        yylval.line = yylineno;
        return ASIG;
    }
    
"," {
        //printf(",\n"); 
        yylval.line = yylineno;
        return COMA;
    }
    
";" {
        ///printf(";\n");
        yylval.line = yylineno;
        return PYC;
    }

"[" {
        yylval.line = yylineno;
        return LCOR;
    }

"]" {
        yylval.line = yylineno;
        return RCOR;
   }
   
"{" {
        yylval.line = yylineno;
        return LKEY;
    }

"}" {
        yylval.line = yylineno;
        return RKEY;
   }
   
"||" {
        yylval.line = yylineno;
        return OR;
   }

"&&" {
        yylval.line = yylineno;
        return AND;
   }
   
"!" {
        yylval.line = yylineno;
        return NOT;
   }
   
">" {
        yylval.line = yylineno;
        return GT;
   }
   
"<" {
        yylval.line = yylineno;
        return LT;
   }
   
">=" {
        yylval.line = yylineno;
        return GET;
   }
   
"<=" {
        yylval.line = yylineno;
        return LET;
   }
   
"==" {
        yylval.line = yylineno;
        return EQ;
   }
    
"!=" {
        yylval.line = yylineno;
        return DIF;
   }
   

    
[ \n\t]+ {}

. {printf("Error Léxico en la linea %d\n", yylineno);}

%%
    
