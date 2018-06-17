#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <string.h>

struct _pila{
    char label[32];
};

typedef struct _pila pila;

pila pilaTrue[100], pilaFalse[100], pilaNext[100];



void pushTrue(char *label);
void popTrue();
char* cimaTrue();

void pushFalse(char *label);
void popFalse();
char* cimaFalse();

void pushNext(char *label);
void popNext();
char* cimaNext();

#endif
