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
void newLabel(char *label);

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
int index_temp = 0;
int index_label = 0;
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
}


%token<sval> ID
%token<num> NUM;
%token COMA PYC
%token INT FLOAT CHAR VOID DOUBLE DEFINE
%token STRUCT RETURN TRUE FALSE
%token IF WHILE
%token LKEY RKEY

/* precedencia de operadores*/
%left ASIG
%left OR
%left AND
%left EQ DIF
%left GT LT GET LET
%left MAS
%left MUL
%left NOT
%nonassoc LPAR RPAR LCOR RCOR


/*Declaración del tipo de los no terminales*/
%type<tipo> type c_array base
//No se incluye a list porque
//no va a tener los atributos heredados
%type<exp> expresion
%type<arg_list> args args_list
%type<sent> body sents sent
//%type<sent_bool> sent_bool

%start program


%%
/*P -> D F */
program : {
    init();
    dirStack.count = 0;
    create_symbol_table();
    create_type_table();
}
decl funcs { print_symbols(0, "global");} ;

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
        //printf("T -> B C\n");
     };

/* B-> void | char | int | float | double */
base: VOID{        
        $$.tipo = 0;
        $$.dim = 1;
        //printf("B->void\n");
        } 
        | CHAR{            
            $$.tipo = 1;
            $$.dim = 2;
            //printf("B->char\n");
        }
        | INT{        
        $$.tipo = 2;
        $$.dim = 4;
        //printf("B->int\n");
        } 
        | FLOAT{            
            $$.tipo = 3;
            $$.dim = 8;
            //printf("B->float\n");
        }
        | DOUBLE{
            $$.tipo = 4;
            $$.dim = 16;
            //printf("B->double\n");
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
            $$.dim = $4.dim*$2.ival;
            //printf("C -> [ num ] C1\n");
        }else{
            yyerror("La dimensión debe de ser un valor entero");
        }
    }

	| {	
		$$.tipo = t_b;
		$$.dim = w_b;
                //printf("C -> null\n");
	};

/* L -> L1 , id | id */
list : list COMA ID {
        //printf("L->L,id\n");
        insert($3, dir, t, 0, NULL, -1);
        dir = dir + w;
        //printf("L->L1, id\n");
        }
        | ID{
            //printf("L->id\n");
            insert($1, dir, t, 0, NULL, -1);
            dir = dir + w;
            //printf("L->id\n");
        };
        
/* F -> define T id ( A ) { D Y } F1 | null */        
funcs : DEFINE type ID LPAR{
        tipo_func = $2.tipo;
        create_symbol_table();
        create_type_table();
        dirStack.count++;
        dirStack.dir[dirStack.count] = dir;
        dir = 0;
        fprintf(yyout, "%s:", $3);
    }args_list RPAR LKEY decl body RKEY {
        print_symbols(symStack.sp,$3);
        delete_symbol_table();
        delete_type_table();
        dir = dirStack.dir[dirStack.count];
        dirStack.count--;    
        insert($3, -1 , tipo_func, 1, $6.args, $6.count); 
        if(tipo_func == $10.tipo){
                fprintf(yyout, "halt\n");
        }else{
            yyerror("El tipo de retorno no coincide con el tipo definido");
        }        
    }funcs 
    //{printf("F -> define T id ( A ) { D Y } F1\n");}
    |{
        //printf("F -> null\n");
    } ;

/* A -> E | void */
args_list: args {
        $$ = $1;
    //printf("A->E\n");
    } 
    | VOID {
        $$.count = -1;
        //printf("A-> void\n");
    }
    ;

/* E-> E, T id | T id */
args: args COMA type ID {
       insert($4, dir, $3.tipo, 2, NULL, -1); 
       dir = dir + $3.dim;
       $1.count++;
       $1.args[$1.count] = $3.tipo;
       $$ = $1;
    }
    | type ID{    
       insert($2, dir, $1.tipo, 2, NULL, -1); 
       dir = dir + $1.dim;
       $$.count= 0;
       $$.args[$$.count] = $1.tipo;
       
    };
    
/* Y -> Z */
body: sents{ $$.tipo = $1.tipo; };

/*  Z -> Z1 X | X */
sents: sents sent {
        //printf("S->S I\n");
        if($1.tipo != 0){
            $$.tipo = $1.tipo;
        }else if($2.tipo != 0){
            $$.tipo = $2.tipo;
        }else{
            $$.tipo = 0;
        }
    }
    | sent{
        $$.tipo = $1.tipo;
        //printf("S->I\n");
    };
    
/* X -> id = G; */
sent:  ID ASIG expresion PYC{   
    if(search_symbol($1, symStack.sp) == 1){
        if(get_tipo($1, symStack.sp)  == $3.tipo){
            fprintf(yyout, "%s = %s\n", $1, $3.dir);
        }else{
            yyerror("Error Semántico: los tipos no coincide");
        }
    }else if(search_symbol($1, 0) == 1){
        if(get_tipo($1, 0)  == $3.tipo){
            fprintf(yyout, "%s = %s\n", $1, $3.dir);
        }else{
            yyerror("Error Semántico: los tipos no coincide");
        }
    }else{
        yyerror("Error Semántico: el id no ha sido declarado");
    }
    $$.tipo = 0;
    newLabel($$.next);
    //printf("X->id= E;\n");
    }
    | RETURN expresion PYC{
        newLabel($$.next);
        $$.tipo = $2.tipo;
        //printf("X->return G;\n");
    }
    |
    IF LPAR sent_bool RPAR sent{
        $$.tipo = 0;
        //printf("X-> if( B ) X\n");
    }
     
    
    ;
    
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
    | expresion MUL expresion {
        $$.tipo = max($1.tipo, $3.tipo);        
        newTemp($$.dir);
        char dirAlpha1[20], dirAlpha2[20];   
        amp($1.dir, $1.tipo, $$.tipo, dirAlpha1);
        amp($3.dir, $3.tipo, $$.tipo, dirAlpha2);
        fprintf(yyout, "%s = %s * %s\n", $$.dir, dirAlpha1, dirAlpha2);        
    }
    | LPAR expresion RPAR {
        $$ = $2;	
    }
    | ID {
        if(search_symbol($1, symStack.sp) == 1){            
            $$.tipo = get_tipo($1, symStack.sp);
            //printf("El tipo de %s es %d\n", $1, $$.tipo);
            strcpy($$.dir, $1);          
        }else if(search_symbol($1, 0) == 1){
            $$.tipo = get_tipo($1, 0);
            //printf("El tipo de %s es %d\n", $1, $$.tipo);
            strcpy($$.dir, $1);
        }else{
            yyerror("El id no fue declarado\n");
            return 0;
        }                   
    }
    | NUM {
        $$.tipo = $1.tipo;
        strcpy($$.dir, $1.sval);        
    };
    
sent_bool: sent_bool  OR sent_bool{}
    | sent_bool  AND sent_bool
    | NOT sent_bool
    | TRUE {
    //printf("B-> true\n");
    }
    | FALSE{
    //printf("B->false\n");
    }
    | expresion op_rel expresion{
        //printf("B-> E oprel E\n");
        };
    
op_rel : GT | LT | EQ | DIF | GET | LET ;

%%



void yyerror(char* s){
    printf("%s , en  la linea %d\n", s, yylval.line);
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

void newLabel(char *label){
    char temp[20];
    strcpy(temp , "L");
    char num[19];
    sprintf(num, "%d", index_label);	
    index_label++;
    strcat(temp,num);
    strcpy(label, temp);
}

void insert(char *id, int dir, int tipo, int sym, int args[], int num){    
    int i;
    strcpy(ctr_symbol.id, id);
    ctr_symbol.dir = dir;
    ctr_symbol.tipo = tipo;
    ctr_symbol.sym = sym;
    if(num != -1){
       for(i=0 ; i<num+1; i++){
            ctr_symbol.args[i] = args[i];
        }
    }
    ctr_symbol.num_args = num;
    //printf("el sp %d\n", symStack.sp);
    if(insert_symbol(ctr_symbol, symStack.sp)==0)
        yyerror("Id duplicado\n");
}


/*void = 0,  char = 1, int = 2, float = 3 y doble =4 */
int  max(int t1, int t2){
    if(t1 == t2)
        return t1;
    else if(t1==1 && t2 == 2){
        return t2;
    }else if( t1 == 2 && t2==1){
        return t1;
    }else if(t1==2 && t2 == 3){
        return t2;
    }else if( t1 == 3 && t2==2){
        return t1;
    }else if(t1==2 && t2 == 4){
        return t2;
    }else if( t1 == 4 && t2==2){
        return t1;
    }
    else if(t1==3 && t2 == 4){
        return t2;
    }else if( t1 == 4 && t2==3){
        return t1;
    }
    else{
        yyerror("Error Semántico: Los tipos no son compatibles funcion max");
        return -1;
    }
}


void amp(char *dir, int t1, int t2, char* res){
    if(t1 == t2){
        strcpy(res, dir);;
    }else if((t1==1 && t2==2) || (t1== 2 && t2 == 1)){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (int) %s\n", temp, dir);
        strcpy(res, temp);
    }else if((t1==2 && t2==3) || (t1== 3 && t2 == 2)){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (float) %s\n", temp, dir);
        strcpy(res, temp);
    }else if((t1==2 && t2==4) || (t1== 4 && t2 == 2)){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (double) %s\n", temp, dir);
        strcpy(res, temp);
    }else if((t1==3 && t2==4) || (t1== 4 && t2 == 3)){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (double) %s\n", temp, dir);
        strcpy(res, temp);
    }
    else{
        yyerror("Error Semántico: Los tipos no son compatibles funcion amp");
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
