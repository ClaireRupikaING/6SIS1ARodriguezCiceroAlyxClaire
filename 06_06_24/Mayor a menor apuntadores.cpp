#include <iostream>
#include <cstdlib>
#include <ctime>   // time en num aleatorios

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
    
    // generar números aleatorios
    srand(static_cast<unsigned int>(time(0)));
    
    // Generar 10 números aleatorios
    for (int i = 0; i < SIZE; i++) {
        *(arr + i) = rand() % 100;
    }
    
    cout << "Original: ";
    printArray(arr, SIZE);
    
    // Ordenar de mayor a menor usando el método burbuja
    bubbleSort(arr, SIZE);
    
    cout << "Ordenado (mayor a menor): ";
    printArray(arr, SIZE);
    
    return 0;
}
