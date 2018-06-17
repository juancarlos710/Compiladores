#include "symbol_table.h"


void init(){
    symTable.count = 0;
}


int  insert_symbol(symbol sym){
    if(search_symbol(sym.id)==0&& symTable.count<SYMNUM+1){
        symTable.symbols[symTable.count] = sym;
	symTable.count++;
	return 1;
    }
    return 0;
}
    
                                                                                                                                                                                                                                   
int search_symbol(char *id){
    int i;
    for( i= 0; i < symTable.count+1; i++){
        if(strcmp(symTable.symbols[i].id, id)==0){
            return 1;
        }
    }
    return 0;
}

int get_tipo(char *id){
	int  i;
	for(i =0; i < symTable.count+1; i++){
		if(strcmp(symTable.symbols[i].id, id)==0){
			return symTable.symbols[i].tipo;
		}
	}
}

void print_symbols(){
    int i;
    printf("Tabla de Símbolos\n");
    printf("Pos\t Id\t Dir\t Tipo\n");
    for(i=0; i < symTable.count; i++){
        printf("%d\t %s\t %d\t %d\n", 
               i, symTable.symbols[i].id, 
                symTable.symbols[i].dir, symTable.symbols[i].tipo);
    }
}
