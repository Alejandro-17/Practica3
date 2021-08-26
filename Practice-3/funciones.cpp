#include <iostream>
#include <string>
#include <fstream>
#include "funciones.h"

funciones::funciones()
{

}

void funciones::codificar(unsigned int &n, string namedata)
{
    string data; //Cadena donde voy a guardar el dato leido
    ifstream infile; // Modo lectura
    infile.open("C:/Users/USUARIO/Documents/Informatica 2/files lab/Practica 3/Practice-3/BD/Sudo.txt");
    if (!infile.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }

       cout << "Leyendo el archivo" << endl;
       infile >> data;

    unsigned long SizeArray1= data.length(); //Tamaño del string data
    unsigned int IndataDec[SizeArray1]; //Arreglo donde voy a guardar la representacion decimal de cada caracter de data

    // En este ciclo guardo la representacion decimal de cada caracter de data en el arreglo IndataDec
    for (unsigned int i=0; i<SizeArray1 ; i++)
    {
        IndataDec[i]=data[i];
    }

    string binario,binario1; //Guardan la representacion binaria de cada caracter de data temporalmente
    unsigned int decimal;
    string binario2,binario3; //Guarda la representacion binaria de cada uno de los caracteres de data

    // En este ciclo convierto cada caracter de decimal a binario y los concateno en un solo string binario2
    for (unsigned int j=0;j<SizeArray1 ; j++)
    {
        decimal=IndataDec[j];
        binario="";

        // Ciclo para convertir decimal a binario, caracter por caracter
        for ( unsigned int i = 0; i < 8; i++)
        {
            binario += (decimal % 2)+48;
            decimal /= 2;
        }
        binario1="";

        // Ciclo para invertir representacion binaria del caracter (Mas significativo a la izquierda)
        for ( int i=7; i>=0 ; i--)
        {
            binario1+=binario[i];
        }
        binario2 += binario1; //Concateno cada representacion binaria
        //cout<<binario2<<endl;
    }
        binario3=binario2; //Saco una copia a binario 2
    // Me aseguro que la semilla no supere la cantidad de bits a codificar
    if (binario3.length()/n==0)
       {
         cout << "\nOye, tu semilla es mayor que la cantidad de bits a codificar " << endl;
         cout << "cantidad de bits: " <<binario3.length()<<endl;
         exit(1);
       }

        // Verifico si hay que agregar bits para que los grupos queden segun la semilla
        unsigned int verificador=binario3.length()%n;
        if(verificador!=0){
        for(unsigned int index=0; index<(n-verificador);index++){
            binario3+="0";
        }}
         cout<<binario3<<endl;
        unsigned int contador=0,SizeF=binario3.length() / n;
        char bloques[SizeF][n]; //En este arreglo guardo los bloques de n bits

        // Guardo bloques de n bits para semillas pares

            for (unsigned int i=0 ;i<SizeF; i++) {
                for (unsigned int j=0 ;j<n;j++) {
                    bloques[i][j]=binario3[contador];
                    contador+=1;
            }}



     /*   //Prubeas
       for (int i=0 ;i<SizeF; i++) {
            for (int j=0 ;j<n;j++) {
                cout<<bloques[i][j];
            }
              cout<<endl;} */
    // Se cierra el archivo abierto
    infile.close();

    // ---------- Empiezo codificacion -----------------------------------------

    // metodo 1 (Primero cambio los valores del ultimo bloque)
    for(unsigned int ind=0; ind<n ; ind++){
        if(bloques[SizeF-1][ind]==48) {
            bloques[SizeF-1][ind]=49;
            continue; }
        if(bloques[SizeF-1][ind]==49) {
            bloques[SizeF-1][ind]=48;}
    }

    //Comparo el numero de 0 y 1 de cada grupo y codifico segun condicion
    unsigned short int cont0=0,cont1=0;
    for (unsigned int i=0 ;i<SizeF; i++) {
         for (unsigned int j=0 ;j<n;j++) {
             if (bloques[i][j]==48)cont0+=1;
             if (bloques[i][j]==49)cont1+=1;
         }
          if (cont0==cont1){
         for (unsigned int j=0; j<n;j++) {


             }
         }
         cout<<endl;}

}
