#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

#include <stdio.h>
#include <string.h>

struct _type{
	char tipo[20];
	int dim;
	int base;
};

typedef struct _type type;

struct _type_table{
	type types[100];
	int count;
};

typedef struct _type_table type_table;


typedef struct _type_stack{
	type_table tables[10];
	int sp;
} type_stack;


type_stack typeStack;


void create_type_table();
int insert_type(type t);
void delete_type_table();
void print_type_table(int table);


#endif
