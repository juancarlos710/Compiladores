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
    RETURN = 269,
    TRUE = 270,
    FALSE = 271,
    IF = 272,
    WHILE = 273,
    LKEY = 274,
    RKEY = 275,
    ASIG = 276,
    OR = 277,
    AND = 278,
    EQ = 279,
    DIF = 280,
    GT = 281,
    LT = 282,
    GET = 283,
    LET = 284,
    MAS = 285,
    MUL = 286,
    NOT = 287,
    LPAR = 288,
    RPAR = 289,
    LCOR = 290,
    RCOR = 291
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
#define RETURN 269
#define TRUE 270
#define FALSE 271
#define IF 272
#define WHILE 273
#define LKEY 274
#define RKEY 275
#define ASIG 276
#define OR 277
#define AND 278
#define EQ 279
#define DIF 280
#define GT 281
#define LT 282
#define GET 283
#define LET 284
#define MAS 285
#define MUL 286
#define NOT 287
#define LPAR 288
#define RPAR 289
#define LCOR 290
#define RCOR 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 46 "parser3.y" /* yacc.c:1909  */

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
    
    struct{
        char next[20];  
        int tipo;
    } sent;
    
    struct{
        char _true[20];
        char _false[20];
    }sent_bool;
    
    int line;
    
    char sval[20];

#line 165 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
