#include<stdio.h>
int main (){

    int a;
    int *ptra;
    a=15;
    ptra=&a; //he pasado la dirección de a a ptra
    printf("La direccion de a es %p el valor de ptra es %p",&a,ptra);
    printf("El valor de a es %d el valor de *ptra es %d",a,*ptra);
    return 0;

}