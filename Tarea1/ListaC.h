#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "NodoC.h"
typedef struct ListaC
{
    NodoC* head;
    
}ListaC;

int size;

ListaC* nuevaLista();
void add(ListaC* l,NodoC* nuevo);
void imprimir(ListaC* l);
void generar(ListaC* l);

void Liberar(ListaC* l);
void guardarRecursivo(NodoC* aux,FILE *fp,char *c);

//Tarea 1
void eliminar(ListaC* l, int posicion);
void eliminarPrimero(ListaC* l);
void eliminarUltimo(ListaC* l);
void get(ListaC* l, int posicion);
