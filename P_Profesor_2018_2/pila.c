#include "pila.h"
int spTrue=0; 
int spFalse=0;
int spNext=0;


void pushTrue(char *label){
    strcpy(pilaTrue[spTrue].label,label);
    spTrue++;
}

void popTrue(){
    spTrue--;
}

char* cimaTrue(){
    return pilaTrue[spTrue-1].label;
}


void pushFalse(char *label){
    strcpy(pilaFalse[spFalse].label,label);
    spFalse++;
}

void popFalse(){
    spFalse--;
}

char* cimaFalse(){
    return pilaFalse[spFalse-1].label;
}

void pushNext(char *label){
    strcpy(pilaNext[spNext].label,label);
    spTrue++;
}

void popNext(){
    spNext--;
}

char* cimaNext(){
    return pilaNext[spNext-1].label;
}
