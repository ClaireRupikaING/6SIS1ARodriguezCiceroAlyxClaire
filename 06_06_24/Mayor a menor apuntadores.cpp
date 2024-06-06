#include <iostream>
#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time en num aleatorios

using namespace std;

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    
    // Inician números aleatorios
    srand(static_cast<unsigned int>(time(0)));
    
    // Generar 10 números aleatorios
    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = rand() % 100;
    }
    
    cout << "Array original: ";
    printArray(arr, SIZE);
    
    // Ordenar el array de mayor a menor usando el método burbuja
    bubbleSort(arr, SIZE);
    
    cout << "Array ordenado (mayor a menor): ";
    printArray(arr, SIZE);
    
    return 0;
}