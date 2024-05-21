#include <iostream>
using namespace std;

bool esPrimo(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i <= x / 2; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int x;
    cout << "Programa hecho por Claire <3 \n";
    cout << "Ingrese un número: ";
    cin >> x;

    if (esPrimo(x)) {
        cout << x << " es un número primo, que bien!." << endl;
    } else {
        cout << x << " no es un número primo, mala suerte." << endl;
    }

    return 0;
}
