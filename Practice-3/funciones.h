#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#ifndef FUNCIONES_H
#define FUNCIONES_H


class funciones
{
public:
    funciones();
    unsigned int n;
    unsigned short int metodo;
    void codificar(unsigned int &n, string namedata);
};

#endif // FUNCIONES_H
