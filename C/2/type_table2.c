#include "type_table.h"


int insert_type(type t){
    int sp = typeStack.sp;
    int cont = typeStack.tables[sp].count;
    
    strcpy(typeStack.tables[sp].types[cont].tipo, t.tipo);
    typeStack.tables[sp].types[cont].dim = t.dim;
    typeStack.tables[sp].types[cont].base = t.base;
    typeStack.tables[sp].count++;
	return cont;
}


void create_type_table(){    
    
    int sp = typeStack.sp++;
    typeStack.tables[sp].count = 0;
    
    strcpy(typeStack.tables[sp].types[0].tipo, "void");
    typeStack.tables[sp].types[0].dim = 1;
    typeStack.tables[sp].types[0].base = -1;
    typeStack.tables[sp].count++;

    strcpy(typeStack.tables[sp].types[1].tipo, "char");
    typeStack.tables[sp].types[1].dim = 2;
    typeStack.tables[sp].types[1].base = -1;
    typeStack.tables[sp].count++;
    
    strcpy(typeStack.tables[sp].types[2].tipo, "int");
    typeStack.tables[sp].types[2].dim = 4;
    typeStack.tables[sp].types[2].base = -1;
    typeStack.tables[sp].count++;
    
    strcpy(typeStack.tables[sp].types[3].tipo, "float");
    typeStack.tables[sp].types[3].dim = 8;
    typeStack.tables[sp].types[3].base = -1;
    typeStack.tables[sp].count++;
    
    strcpy(typeStack.tables[sp].types[4].tipo, "double");
    typeStack.tables[sp].types[4].dim = 16;
    typeStack.tables[sp].types[4].base = -1;
    typeStack.tables[sp].count++;
    
}

void delete_type_table(){
    typeStack.sp--;
}


void print_type_table(int table){
    int i;
    printf("pos\ttipo\tdim\tbase\n");
    for(i=0; i < typeStack.tables[table].count+1; i++){
        printf("%d\t%s\t%d\t%t\n", i, typeStack.tables[table].types[i].tipo,
               typeStack.tables[table].types[i].dim, typeStack.tables[table].types[i].base);        
    }
}
