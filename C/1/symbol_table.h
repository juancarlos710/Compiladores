 /* 
 * File:   symbol_table.h
 * Author: Ulises Mercado Martínez
 *
 * Created on 18 de mayo de 2017, 11:22
 */

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <string.h>    

#define SYMNUM 50
    
    struct _symbol{
        char id[20];
        int tipo;
        int dir;
    };
    
    typedef struct _symbol symbol;
    
    
    struct _symbol_table{
        symbol symbols[SYMNUM];
        int count;
    };
    
    typedef struct _symbol_table symbol_table;
    
    symbol_table symTable;
    
    
    void init();
    int insert_symbol(symbol sym);    
    int search_symbol(char *id);
    int get_tipo(char *id);
    void print_symbols();
    

#ifdef __cplusplus
}
#endif

#endif /* SYMBOL_TABLE_H */

