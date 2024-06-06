#include <stdio.h>
#include <iostream>
using namespace std;

void cuboPorReferencia( int *ptrN );

int main (){

    int num = 5;
    cout << "El valor original el número es: " << num << endl;
    // Pasa la direccion de numero a CuboPorReferencia
    cuboPorReferencia( &num );
    cout << "El nuevo valor de número es: " << num << endl;
    return 0;
}

void cuboPorReferencia ( int *ptrN ){
    *ptrN = (*ptrN) * (*ptrN) * (*ptrN);
}