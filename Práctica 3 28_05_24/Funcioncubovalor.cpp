#include <stdio.h>
#include <iostream>
using namespace std;
 
void cuboPorReferencia( int *ptrN );
 
int main()
{
int num = 5;
cout<< "El valor origial el numero es: " << num <<endl;
/* pasa la dirección de numero a cuboPorReferencia */
cuboPorReferencia( &num );
cout<< "El nuevo valor de numero es: " << num <<endl;
return 0;
}
/* calcula el cubo de *ptrN; modifica la variable numero en main */
void cuboPorReferencia( int *ptrN )
{
*ptrN = *ptrN * *ptrN * *ptrN; /* cubo de *ptrN */
}