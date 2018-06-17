%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "type_table.h"

extern FILE* yyin;
extern int yylex();
extern FILE* yyout;
//simbolo que va entrar a la tabla de simbolos
symbol ctr_symbol;

void insert(char *id, int dir, int tipo, int sym, int args[], int num);
void amp(char *dir, int t1, int t2, char* res);
int max(int t1, int t2);
void newTemp(char *dir);

void yyerror(char* s);

// variables que sustituye en atributo tipo
// de el no terminal list
int w=0, t=0;

// globales para B
int w_b, t_b;

int dir = 0;

int tipo_func;

struct _dir_stack{
    int dir[20];
    int count;
};

typedef struct _dir_stack  dir_stack;

dir_stack dirStack;

dirStack.count = 0;

int index_temp = 0;
%} 


%union{
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
}


%token<sval> ID
%token<num> NUM;
%token COMA PYC
%token INT FLOAT CHAR VOID DOUBLE DEFINE
%token STRUCT
%token LCOR RCOR LKEY RKEY
/* precedencia de operadores*/
%left MAS
%left MUL
%left ASIG
%nonassoc LPAR RPAR

/*Declaración del tipo de los no terminales*/
%type<tipo> type c_array base
//No se incluye a list porque
//no va a tener los atributos heredados
%type<exp> expresion
%type<arg_list> args args_list

%start program


%%
/*P -> D F */
program : decl {print_symbols(0);} funcs {printf("Se realizo correctamente el análisis\n");} ;

/* D -> D T L ; | null */
decl: decl type { 
        t = $2.tipo;
        w = $2.dim;
    } list PYC{
     //printf("D-> D T L;\n");
    } 
    
    | { //printf("D->3\n");
    };

/* T -> B C */
type: base{
	t_b = $1.tipo;
	w_b = $1.dim;
     } c_array{ 
	$$.tipo = $3.tipo;
	$$.dim = $3.dim;
     };

/* B-> void | char | int | float | double */
base: VOID{        
        $$.tipo = 0;
        $$.dim = 1;
        } 
        | CHAR{            
            $$.tipo = 1;
            $$.dim = 2;
        }
        | INT{        
        $$.tipo = 2;
        $$.dim = 4;
        } 
        | FLOAT{            
            $$.tipo = 3;
            $$.dim = 8;
        }
        | DOUBLE{
            $$.tipo = 4;
            $$.dim = 16;
        }
        ;

/* C -> [ num ] C1 | null */
c_array : LCOR NUM RCOR c_array {
        type t;
        if($2.tipo ==0){
            strcpy(t.tipo, "array");
            t.dim = $2.ival;
            t.base = $4.tipo;
            $$.tipo = insert_type(t);
            $$.dim = $4.dim;
        }else{
            yyerror("La dimensión debe de ser un valor entero");
        }
    }

	| {	
		$$.tipo = t_b;
		$$.dim = w_b;
	};

/* L -> L1 , id | id */
list : list COMA ID {
        //printf("L->L,id\n");
        insert($3, dir, t, 0, NULL, -1);
        dir = dir + w;
        }
        | ID{
            //printf("L->id\n");
            insert($1, dir, t, 0, NULL, -1);
            dir = dir + w;
        };
        
/* F -> define T id ( A ) { D Y } F1 | null */        
funcs : DEFINE type ID LPAR{
        tipo_func = $2.tipo;
        create_symbol_table();
        create_type_table();
        dirStack.count++;
        dirStack.dir[dirStack.count] = dir;
        dir = 0;
    }args_list RPAR LKEY sents RKEY {
        delete_symbol_table();
        delete_type_table();
        dir = dirStack.dir[dirStack.count];
        dirStack.count--;    
        insert($3, -1 , tipo_func, 1, $6.args, $6.count); 
    }funcs 
    
    | ;
    

/* A -> E | void */
args_list: args {
        $$ = $1;
    } 
    | VOID {
        $$.count = -1;
    }
    ;

/* E-> E, T id | T id */
args: args COMA type ID {
       insert($4, dir, t, 2, NULL, -1); 
       dir = dir + w;
       $1.count++;
       $1.args[$1.count] = $3.tipo;
       $$ = $1;
    }
    | type ID{    
       insert($2, dir, t, 2, NULL, -1); 
       dir = dir + w;
       $$.count= 0;
       $$.args[$$.count] = $1.tipo;
       
    };

/*  Z -> Z1 X | X */
sents: sents sent {
        //printf("S->S I\n");
        }
    | sent{
        //printf("S->I\n");
    };
    
/* X -> id = G; */
sent:  ID ASIG expresion PYC{   
    if(search_symbol($1, symStack.sp) == 1){
        if(get_tipo($1, symStack.sp)  == $3.tipo){
            fprintf(yyout, "%s = %s\n", $1, $3.dir);
        }else{
            yyerror("Error Semántico: los tipos no coincide\n");
        }
    }else{
        yyerror("Error Semántico: el id no ha sido declarado\n");
    }
    //printf("I->id= E;\n");
    };
    
/* G -> G1 + G2 | G1 * G2  |(G) | id | num */
expresion : expresion MAS expresion {
        $$.tipo = max($1.tipo, $3.tipo);        
        newTemp($$.dir);
        char dirAlpha1[20], dirAlpha2[20];   
        amp($1.dir, $1.tipo, $$.tipo, dirAlpha1);
        amp($3.dir, $3.tipo, $$.tipo, dirAlpha2);
        fprintf(yyout, "%s = %s + %s\n", $$.dir, dirAlpha1, dirAlpha2);
        //printf("E->E+E\n");
    }
    | expresion MUL expresion{
        $$.tipo = max($1.tipo, $3.tipo);        
        newTemp($$.dir);
        char dirAlpha1[20], dirAlpha2[20];   
        amp($1.dir, $1.tipo, $$.tipo, dirAlpha1);
        amp($3.dir, $3.tipo, $$.tipo, dirAlpha2);
        fprintf(yyout, "%s = %s * %s\n", $$.dir, dirAlpha1, dirAlpha2);        
    }
    | LPAR expresion RPAR{
        $$ = $2;	
    }
    | ID{
        $$.tipo = get_tipo($1, symStack.sp);
        strcpy($$.dir, $1);         
    }
    | NUM{
        $$.tipo = $1.tipo;
        strcpy($$.dir, $1.sval);        
    };
    
%%



void yyerror(char* s){
    printf("%s\n", s);
}


void newTemp(char *dir){
    char temp[20];
    strcpy(temp , "t");
    char num[19];
    sprintf(num, "%d", index_temp);	
    index_temp++;
    strcat(temp,num);
    strcpy(dir, temp);
}

void insert(char *id, int dir, int tipo, int sym, int args[], int num){    
    strcpy(ctr_symbol.id, id);
    ctr_symbol.dir = dir;
    ctr_symbol.tipo = tipo;
    ctr_symbol.sym = sym;
    if(num != -1)
        ctr_symbol.args =args;
    ctr_symbol.num_args = num;
    if(insert_symbol(ctr_symbol, symStack.sp)==0)
        yyerror("Id duplicado\n");
}

int  max(int t1, int t2){
    if(t1 == t2)
        return t1;
    else if(t1==0 && t2 == 1){
        return t2;
    }else if( t1 == 1 && t2==0){
        return t1;
    }else{
        yyerror("Error Semántico: Los tipos no son compatibles");
    }
}


void amp(char *dir, int t1, int t2, char* res){
    if(t1 == t2){
        strcpy(res, dir);;
    }else if(t1==0 && t2==1){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (float) %s\n", temp, dir);
        strcpy(res, temp);
    }else if(t1== 1 && t2 == 0){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (float) %s\n", temp, dir);
        strcpy(res, temp);
    }else{
        yyerror("Error Semántico: Los tipos no son compatibles");
    }
}


int main(int argc, char** argv){
    FILE* file;
    if(argc >1){
        file = fopen(argv[1], "r");
        if(file==NULL){
            printf("no existe el fichero %s\n", argv[1]);
            exit(1);
        }
        char nombre[50];
        strcpy(nombre, argv[1]);
        strcat(nombre, ".ci");
        yyout = fopen(nombre, "w");
        //printf("se abrio el archivo\n");
        yyin = file;        
        //yylval.sval = (char*) malloc(2*sizeof(char));
        yyparse();
        fclose(yyin);
        fclose(yyout);
    }
    
    return 1;
}

