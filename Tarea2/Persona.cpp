#include "Persona.h"
Persona::Persona(){}
Persona::Persona(int edad, string nombre){
    this->edad = edad;
    this->nombre = nombre;
}

void Persona::setEdad(int edad){
    this->edad = edad;
}

void Persona::setNombre(string nombre){
    this->nombre = nombre;
}

int Persona::getEdad(){
    return edad;
}

string Persona::getNombre(){
    return nombre;
}