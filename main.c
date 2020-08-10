#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "ListaC.h"
#include "NodoC.h"
int main(){
    NodoA* a=newNodoC(10);
    NodoA* b=newNodoC(3);
    NodoA* d=newNodoC(15);
    NodoC* c=newNodoC(25);
    ListaC* l=nuevaLista();
    add(l,a);
    add(l,b);
    add(l,c);
    add(l,d);
    imprimir(l);
    printf("\n");
    eliminar(l,2);
    imprimir(l);
    get(l,3);
    generar(l);
    Liberar(l);
    free(l);
    return 0;
}