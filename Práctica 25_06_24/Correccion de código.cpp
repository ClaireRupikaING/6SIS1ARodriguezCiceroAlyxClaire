#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    FILE *ptrCF;
    ptrCF = fopen("Cliente.dat", "w"); 
    if(ptrCF == NULL){
        cout << "El Archivo no puede abrirse" << endl;
    } else {
        cout << "Bienvenido al Banco de la Almas Perdidas" << endl;
        cout << "Ingrese numero de cuenta, nombre, saldo y EDF " << endl;
        
        int cuenta;
        char nombre[30];
        double saldo;
        char edf[10];
        
        while(true){ 
            cout << ":) ?" << endl;
            cin >> cuenta;
			cin >> nombre;
			cin >> saldo;
			cin >> edf;
            
            fprintf(ptrCF, "%d %s %.2f %s\n", cuenta, nombre, saldo, edf);
            
            char respuesta;
            cout << "Quiere agregar otra Alma? (S/N)" << endl;
            cin >> respuesta;
    
            if(tolower(respuesta) == 'n'){ 
                break; 
            }
        }
        fclose(ptrCF);
        
        char mostrar;
        cout << "Quiere ver los Datos Guardados de las cuentas? (S/N)" << endl;
        cin >> mostrar;
        
        if(tolower(mostrar) == 's'){ 
            FILE *ptrCR = fopen("Cliente.dat", "r");
            if(ptrCR!= NULL){
                int cuenta_leida;
                char nombre_leida[30];
                double saldo_leida;
                char edf_leida[10];
                
                while(fscanf(ptrCR, "%d %s %lf %s", &cuenta_leida, nombre_leida, &saldo_leida, edf_leida) == 4){
                	printf("Aqui estan los datos de las Victimas que vendieron su Alma\n");
                    printf("Cuenta: %d, Nombre: %s, Saldo: %.2f, EDF: %s\n", cuenta_leida, nombre_leida, saldo_leida, edf_leida);
                }
                fclose(ptrCR);
                
                FILE *ptrCR2 = fopen("Cliente.dat", "r");
                if(ptrCR2!= NULL){
                    int cuenta_leida;
                    char nombre_leida[30];
                    double saldo_leida;
                    char edf_leida[10];
                    
                    while(fscanf(ptrCR2, "%d %s %lf %s", &cuenta_leida, nombre_leida, &saldo_leida, edf_leida) == 4){
                    	printf("Aqui esta la Direccion de la memoria que esta ocupando su Alma\n");
                        printf("Cuenta: %p, Nombre: %p, Saldo: %p, EDF: %p\n", &cuenta_leida, nombre_leida, &saldo_leida, edf_leida);
                    }
                    fclose(ptrCR2);
                } else {
                    cout << "No se puede abrir el archivo para lectura" << endl;
                }
            } else {
                cout << "No se puede abrir el archivo para lectura" << endl;
            }
        }
    }
    return 0;
}