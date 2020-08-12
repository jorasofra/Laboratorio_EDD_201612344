#include "ListaC.h"

    void add(ListaC* l,NodoC* nuevo){
    if(l->head==NULL){
        l->head=nuevo;
    }else if(nuevo->val<=l->head->val){
        nuevo->derecha=l->head;
        l->head->izquierda=nuevo;
        l->head=nuevo;
    }else{
        NodoC* aux=l->head;
        while(aux->derecha!=NULL){
            if(aux->val>nuevo->val){
                NodoC* ant=aux->izquierda;
                ant->derecha=nuevo;
                nuevo->izquierda=ant;
                nuevo->derecha=aux;
                aux->izquierda=nuevo;
                size++;
                return;
            }else if(nuevo->val<=aux->derecha->val){
                NodoC *siguiente=aux->derecha;
                aux->derecha=nuevo;
                nuevo->derecha=aux;
                nuevo->derecha=siguiente;
                siguiente->izquierda=nuevo;
                nuevo->izquierda=aux;
                size++;
                return;
            }
            aux=aux->derecha;
        }
        aux->derecha=nuevo;
        nuevo->izquierda=aux;
    }
    size++;
}

void Liberar(ListaC* l){
    NodoA* aux=l->head;
    NodoA* tmp;
    while(aux!=NULL){
        tmp=aux->derecha;
        free(aux);
        aux=tmp;
    }
    size = 0;
}

void imprimir(ListaC* l){
    NodoA* aux=l->head;
    while(aux!=NULL){
        printf("El valor es %i \n",aux->val);
        aux=aux->derecha;
    }
    printf("El tamanio de la lista es %i \n", size);
}
ListaC* nuevaLista(){
    ListaC* nueva=(ListaC*) malloc(sizeof(ListaC));
    nueva->head=NULL;
    size = 0;
    return nueva;
}
void generar(ListaC* l){
    FILE * fp;
    fp=fopen("./cadigo.txt","w");
    if(fp==NULL){
        printf("Error");
        return;
    }
    char cad[1024];
    sprintf(cad,"digraph G{ \n node[shape=\"box\"];\n");
    fputs(cad,fp);
    NodoC* aux;
    aux=l->head;
    guardarRecursivo(aux,fp,cad);
    sprintf(cad,"}\n");
    fputs(cad,fp);
    fclose(fp);
}

void guardarRecursivo(NodoC* aux,FILE* fp,char c[]){
    if(aux==NULL){
        return;
    }else{
        if(aux->derecha!=NULL){
            
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
            guardarRecursivo(aux->derecha,fp,c);
            sprintf(c,"node%p->node%p;\n node%p->node%p;\n",&(*aux),&(*aux->derecha),&(*aux->derecha),&(*aux));
            fputs(c,fp);
        }else{
            sprintf(c,"node%p[label=\"%i\"]\n",&(*aux),aux->val);
            fputs(c,fp);
        }
    }
}

void eliminarPrimero(ListaC* l){
    NodoA* aux=l->head;
    if(aux != NULL){
        l->head=aux->derecha;
        if(aux->derecha != NULL){
            aux->derecha->izquierda=NULL;
        }
        free(aux);
        size--;
    }
}

void eliminarUltimo(ListaC* l){
    NodoA* aux=l->head;
    if(aux->derecha == NULL){
        eliminarPrimero(l);
    } else if (aux != NULL){
        while(aux->derecha != NULL){
            aux=aux->derecha;
        }
        aux->izquierda->derecha=NULL;
        aux->izquierda=NULL;
        free(aux);
        size--;
    }
}

void eliminar(ListaC* l, int posicion) {
    NodoA* aux=l->head;
    if(posicion > size || posicion < 1){
        return;
    }else if (posicion == 1) {
        eliminarPrimero(l);
    } else if (posicion == size) {
        eliminarUltimo(l);
    } else if(aux != NULL){
        for(int i = 1; i < size ; i++){
            if (i == posicion){
                NodoC* aux1 = aux->izquierda;
                NodoC* aux2 = aux->derecha;
                aux1->derecha = aux2;
                aux2->izquierda = aux1;
                free(aux);
                size--;
                return;
            }
            aux = aux->derecha;
        }
    }
}

void get(ListaC* l, int posicion){
    NodoA* aux = l->head;
    if(posicion < 1 || posicion > size){
        printf("El indice de busqueda sobrepasa el tamanio de la lista \n");
    } else if(aux != NULL){
        for(int i = 1; i <= posicion; i++){
            if(i == posicion){
                printf("El valor buscado es: %i \n", aux->val);
                return;
            }
            aux = aux->derecha;
        }
    }
}