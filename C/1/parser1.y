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

void insert(char *id, int dir, int tipo);
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
    
    int line;
    
    char sval[20];
}


%token<sval> ID
%token<num> NUM;
%token COMA PYC
%token INT FLOAT
%token LCOR RCOR
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

%start program


%%
program : decl {print_symbols();} sents {printf("Se realizo correctamente el análisis\n");} ;

decl: decl type { 
        t = $2.tipo;
        w = $2.dim;
    } list PYC{
     //printf("D-> D T L;\n");
    } 
    
    | { //printf("D->3\n");
    };

type: base{
	t_b = $1.tipo;
	w_b = $1.dim;
     } c_array{ 
	$$.tipo = $3.tipo;
	$$.dim = $3.dim;
     };


base: INT{
        //printf("T->int\n");
        $$.tipo = 1;
        $$.dim = 2;
        } 
        | FLOAT{
            //printf("T->float\n");
            $$.tipo = 2;
            $$.dim = 4;
        };


c_array : LCOR NUM RCOR c_array {
	 type t;
	 if($2.tipo ==1){
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
	}

;

list : list COMA ID {
        //printf("L->L,id\n");
        insert($3, dir, t);
        dir = dir + w;
        }
        | ID{
            //printf("L->id\n");
            insert($1, dir, t);
            dir = dir + w;
        };

sents: sents sent {
        //printf("S->S I\n");
        }
    | sent{
        //printf("S->I\n");
    };
    
sent:  ID ASIG expresion PYC{   
    if(search_symbol($1) == 1){
        if(get_tipo($1)  == $3.tipo){
            fprintf(yyout, "%s = %s\n", $1, $3.dir);
        }else{
            yyerror("Error Semántico: los tipos no coincide\n");
        }
    }else{
        yyerror("Error Semántico: el id no ha sido declarado\n");
    }
    //printf("I->id= E;\n");
    };
    
expresion : expresion MAS expresion {
        $$.tipo = max($1.tipo, $3.tipo);
        //strcpy($$.dir , newTemp());
        newTemp($$.dir);
        char dirAlpha1[20], dirAlpha2[20];   
        amp($1.dir, $1.tipo, $$.tipo, dirAlpha1);
        amp($3.dir, $3.tipo, $$.tipo, dirAlpha2);
        fprintf(yyout, "%s = %s + %s\n", $$.dir, dirAlpha1, dirAlpha2);
        //printf("E->E+E\n");
    }
    | expresion MUL expresion{
       $$.tipo = max($1.tipo, $3.tipo);
        //strcpy($$.dir , newTemp());
        newTemp($$.dir);
        char dirAlpha1[20], dirAlpha2[20];   
        amp($1.dir, $1.tipo, $$.tipo, dirAlpha1);
        amp($3.dir, $3.tipo, $$.tipo, dirAlpha2);
        fprintf(yyout, "%s = %s * %s\n", $$.dir, dirAlpha1, dirAlpha2);
        //printf("E->E*E\n");
    }
    | LPAR expresion RPAR{
        $$ = $2;
	//$$.dir = $2.dir;
	//$$.tipo = $2.tipo;
        //printf("E->(E)\n");
    }
    | ID{
        $$.tipo = get_tipo($1);
        strcpy($$.dir, $1);    
        //printf("E->id\n");
    }
    | NUM{
        $$.tipo = $1.tipo;
        strcpy($$.dir, $1.sval);
        //printf("E->num\n");
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

void insert(char *id, int dir, int tipo){
    //ctr_symbol.id = realloc(ctr_symbol.id, strlen(ctr_symbol.id)*sizeof(char));
    //printf("%s, %d, %d\n", id, dir, tipo);
    strcpy(ctr_symbol.id, id);
    ctr_symbol.dir = dir;
    ctr_symbol.tipo = tipo;
    if(insert_symbol(ctr_symbol)==0)
	yyerror("Id duplicado\n");
}

int  max(int t1, int t2){
    if(t1 == t2)
        return t1;
    else if(t1==1 && t2 == 2){
        return t2;
    }else if( t1 == 2 && t2==1){
        return t1;
    }else{
        yyerror("Error Semántico: Los tipos no son compatibles");
    }
}


void amp(char *dir, int t1, int t2, char* res){
    if(t1 == t2){
        strcpy(res, dir);;
    }else if(t1==1 && t2==2){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (float) %s\n", temp, dir);
        strcpy(res, temp);
    }else if(t1== 2 && t2 == 1){
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

