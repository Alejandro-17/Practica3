#include <iostream>
#include <string>
#include <fstream>
#include "funciones.h"

using namespace std;

int main()
{
  string prueba="hola";
  funciones pruebas;
  unsigned int semilla;
  cout<<"Ingrese semilla, MAXIMO 8: "<<endl;
  cin>>semilla;
  pruebas.codificar(semilla,prueba);

    return 0;
}
