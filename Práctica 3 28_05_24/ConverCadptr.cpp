#include <stdio.h>
#include <iostream>
#include <ctype.h>
using namespace std;

void imprimeCaracteres ( const char *ptrS);

int main (){

    char cadena [] = "Caracteres y $32.98";
    cout << "La cadena antes de la conversión es: " << cadena << endl;
    //printf( "La cadena antes de la conversion es : %s", cadena);
    convertidor( cadena );
    cout << "La cadena despue de la conversion es: " << cadena << endl;
    //printf ("\nLa cadena despues de la conversion es: %s/n", cadena );
    return 0;
}

//Convierte una cadena a letras mayusculas
void convertidor (char *ptrS ){
    while ( *ptrS != '\0') {
        if ( islower ( *ptrS ) ){
            *ptrS = toupper ( *ptrS );
        }
        ++ptrS;
    } 
}