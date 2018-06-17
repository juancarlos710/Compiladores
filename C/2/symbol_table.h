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
        int sym;
        int args[30];
        int num_args;
    };
    
    typedef struct _symbol symbol;
    
    
    struct _symbol_table{
        symbol symbols[SYMNUM];
        int count;
    };
    
    typedef struct _symbol_table symbol_table;
    
    struct _symbol_stack{
        symbol_table tables[20];
        int sp;
    };
    
    typedef struct _symbol_stack symbol_stack;
    
    symbol_stack symStack;
    
    void init();
    int insert_symbol(symbol sym, int table);    
    int search_symbol(char *id, int table);
    int get_tipo(char *id, int table);
    void print_symbols(int table);
    void create_symbol_table();
    void delete_symbol_table();
    

#ifdef __cplusplus
}
#endif

#endif /* SYMBOL_TABLE_H */

