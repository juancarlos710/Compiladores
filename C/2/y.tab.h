/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUM = 259,
    COMA = 260,
    PYC = 261,
    INT = 262,
    FLOAT = 263,
    CHAR = 264,
    VOID = 265,
    DOUBLE = 266,
    DEFINE = 267,
    STRUCT = 268,
    LCOR = 269,
    RCOR = 270,
    LKEY = 271,
    RKEY = 272,
    MAS = 273,
    MUL = 274,
    ASIG = 275,
    LPAR = 276,
    RPAR = 277
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define COMA 260
#define PYC 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define VOID 265
#define DOUBLE 266
#define DEFINE 267
#define STRUCT 268
#define LCOR 269
#define RCOR 270
#define LKEY 271
#define RKEY 272
#define MAS 273
#define MUL 274
#define ASIG 275
#define LPAR 276
#define RPAR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 47 "parser2.y" /* yacc.c:1909  */

    struct{
        int ival;
        double dval;
        //char *sval;
        char sval[20];
        int tipo;
    } num;
    
    struct{
        char dir[20];
        int tipo;        
    }exp;
    
    struct{
        int tipo;
        int dim;        
    } tipo;
    
    struct{
        int args[30];
        int count;
    } arg_list;
    
    int line;
    
    char sval[20];

#line 127 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
