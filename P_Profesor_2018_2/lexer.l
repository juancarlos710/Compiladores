%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%option yylineno
%option noyywrap

digito [0-9]
letra [a-zA-Z_]

%%


int   { printf("%s\n",yytext);return INT;}
float { printf("%s\n",yytext); return FLOAT;}
if      { printf("%s\n",yytext);return IF;}
else    { printf("%s\n",yytext);return ELSE;}
while   { printf("%s\n",yytext);return WHILE;}
do      { printf("%s\n",yytext);return DO;}
{letra}({letra}|{digito})*  {
                    strcpy(yylval.id, yytext);
                    printf("%s\n",yytext);
                    return ID;
        }
        
"{" { printf("%s\n",yytext);return LKEY;}
"}" { printf("%s\n",yytext); return  RKEY;}
"(" { printf("%s\n",yytext); return  LPAR;}
")" { printf("%s\n",yytext); return  RPAR;}
"+" { printf("%s\n",yytext); return  MAS;}
"*" { printf("%s\n",yytext); return  MUL;}
"=" { printf("%s\n",yytext); return  ASIG;}
"==" { printf("%s\n",yytext); return  EQ;}
"!="    { printf("%s\n",yytext); return  NE;}
"!" { printf("%s\n",yytext); return  NOT;}
"<" { printf("%s\n",yytext); return  LT;}
">" { printf("%s\n",yytext); return  GT;}
"<=" { printf("%s\n",yytext); return  LTE;}
">=" { printf("%s\n",yytext); return  GTE;}
"||" { printf("%s\n",yytext); return  OR;}
"&&" { printf("%s\n",yytext); return  AND;}
"," { printf("%s\n",yytext); return  COMA;}
";" { printf("%s\n",yytext); return  PYC;}
[ \t\n] {}
<<EOF>> { printf("%s\n",yytext); return  0;}
{digito}+   { 
                yylval.numero.valor.ival = atoi(yytext);
                yylval.numero.tipo = 0;
                return NUM;
            }

. { printf("Error Léxico: %s\n", yytext);}

%%
