#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "Persona.h"
using namespace std;

int main()
{
    Persona per1;
    Persona per2;
    Persona per3;
    Persona per4;
    
    per1.setEdad(18);
    per1.setNombre("Luis");
    
    per2.setEdad(39);
    per2.setNombre("Matias");
    
    per3.setEdad(67);
    per3.setNombre("Alberto");
    
    per4.setEdad(80);
    per4.setNombre("Ana");
    
    Queue<Persona>*cola=new Queue<Persona>();
    cola->insertar(per1);
    cola->insertar(per2);
    cola->insertar(per3);
    cola->insertar(per4);
    cola->imprimir();
    /*cola->enqueue(10);
    cola->enqueue(20);
    cola->enqueue(30);
    cout<<cola->dequeue()->getValue()<<endl;
    cout<<cola->dequeue()->getValue()<<endl;
    cola->vaciar();
    delete cola;*/
    return 0;
}
