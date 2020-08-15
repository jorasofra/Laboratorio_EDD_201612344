#include <iostream>
using namespace std;

class Persona{
private:
    int edad;
    string nombre;
public:
    Persona();
    Persona(int edad, string nombre);
    void setEdad(int edad);
    void setNombre(string nombre);
    int getEdad();
    string getNombre();
};