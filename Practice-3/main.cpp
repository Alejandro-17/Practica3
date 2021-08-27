#include <iostream>
#include <string>
#include <fstream>
#include "funciones.h"

using namespace std;

int main()
{
  string prueba="Sudo.txt";
  funciones pruebas;
  unsigned int semilla,metodo;
  cout<<"Ingrese semilla: "<<endl;
  cin>>semilla;
  cout<<"\nQuiere codificar por metodo 1 || 2?"<<endl;
  cin>>metodo;
  pruebas.codificar(semilla,metodo,prueba);

    return 0;
}
