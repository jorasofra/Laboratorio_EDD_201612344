#include "queue.h"

template<class T>
Queue<T>::Queue()
{
    this->top=NULL;
    this->bottom=NULL;
}

template<class T>
Queue<T>::~Queue(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp=NULL;
    while(aux!=NULL){
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}


template<class T>
void Queue<T>::enqueue(T valor){
    if(this->top==NULL){
        NodoGenerico<T> *nuevo=new NodoGenerico<T>(valor);
        this->top=nuevo;
        this->bottom=nuevo;
    }else{
        NodoGenerico<T>*nuevo=new NodoGenerico<T>(valor);
        NodoGenerico<T>*aux=this->bottom;
        aux->setSiguiente(nuevo);
        this->bottom=nuevo;
    }
}

template <class T>
NodoGenerico<T>* Queue<T>::dequeue(){
    if(top==NULL){return NULL;}
    NodoGenerico<T>*aux=top;
    top=top->getSiguiente();
    return aux;
}

template<class T>
void Queue<T>::vaciar(){
    NodoGenerico<T>*aux=this->top;
    NodoGenerico<T>*tmp;
    while(aux!=NULL){
        //cout<<aux->getValue()<<"\n";
        tmp=aux->getSiguiente();
        delete aux;
        aux=tmp;
    }
}

template<class T>
void Queue<T>::insertar(T persona){
    if(this->top == NULL){
        NodoGenerico<T> *n = new NodoGenerico<T>(persona);
        this->top = n;
        this->bottom = n;
    } else if(persona.getEdad() >= 65){
        NodoGenerico<T> *n = new NodoGenerico<T>(persona);
        n->setSiguiente(top);
        this->top = n;
    } else {
        NodoGenerico<T> *n = new NodoGenerico<T>(persona);
        bottom->setSiguiente(n);
        this->bottom = n;
    }
}

template<class T>
void Queue<T>::imprimir(){
    NodoGenerico<T> *aux = top;
    while(aux != NULL){
        cout << aux->getValue().getNombre() << " " << aux->getValue().getEdad() << "\n";
        aux = aux->getSiguiente();
    }
    cout << endl;
}