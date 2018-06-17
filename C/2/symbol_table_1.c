#include "symbol_table.h"


void init(){
     symStack.sp = 0;
}


int  insert_symbol(symbol sym, int table){    
    int cont = symStack.tables[table].count;
    if(search_symbol(sym.id, table)==0&& symStack.tables[table].count<SYMNUM+1){
        symStack.tables[table].symbols[cont] = sym;
	symStack.tables[table].count++;
	return 1;
    }
    return 0;
}
    
                                                                                                                                                                                                                                   
int search_symbol(char *id, int table){
    int i;
    for( i= 0; i < symStack.tables[table].count+1; i++){
        if(strcmp(symStack.tables[table].symbols[i].id, id)==0){
            return 1;
        }
    }
    return 0;
}

int get_tipo(char *id, int table){
	int  i;
	for(i =0; i < symStack.tables[table].count+1; i++){
		if(strcmp(symStack.tables[table].symbols[i].id, id)==0){
			return symStack.tables[table].symbols[i].tipo;
		}
	}
	return -1;
}

void print_symbols(int table){
    int i;
    printf("Tabla de Símbolos\n");
    printf("Pos\t Id\t Dir\t Tipo\n");
    for(i=0; i < symStack.tables[table].count; i++){
        printf("%d\t %s\t %d\t %d\n", 
               i, symStack.tables[table].symbols[i].id, 
                symStack.tables[table].symbols[i].dir, symStack.tables[table].symbols[i].tipo);
    }
}


void create_symbol_table(){
    symStack.sp++;    
    symStack.tables[symStack.sp].count = 0;    
}


void delete_symbol_table(){
    symStack.tables[symStack.sp].count = 0;
    symStack.sp--;    
}
