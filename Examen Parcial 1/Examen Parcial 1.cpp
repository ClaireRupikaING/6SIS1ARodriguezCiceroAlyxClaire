#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int NUM_PRODUCTOS = 100;
const int NUM_MESES = 12;

const string NOMBRES_MESES[NUM_MESES] = {
    "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
    "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
};

void calcularVentasProductos(const vector<vector<int>>& ventas, vector<int>& ventasProductos) {
    for (int i = 0; i < NUM_PRODUCTOS; ++i) {
        ventasProductos[i] = 0;
        for (int j = 0; j < NUM_MESES; ++j) {
            ventasProductos[i] += ventas[i][j];
        }
    }
}

void calcularVentasMeses(const vector<vector<int>>& ventas, vector<int>& ventasMeses) {
    for (int j = 0; j < NUM_MESES; ++j) {
        ventasMeses[j] = 0;
        for (int i = 0; i < NUM_PRODUCTOS; ++i) {
            ventasMeses[j] += ventas[i][j];
        }
    }
}

void productoMasVendidoPorMes(const vector<vector<int>>& ventas, vector<int>& productoMasVendido) {
    for (int j = 0; j < NUM_MESES; ++j) {
        int maxVentas = -1;
        for (int i = 0; i < NUM_PRODUCTOS; ++i) {
            if (ventas[i][j] > maxVentas) {
                maxVentas = ventas[i][j];
                productoMasVendido[j] = i;
            }
        }
    }
}

void imprimirResultados(const vector<int>& ventasProductos, const vector<int>& ventasMeses, const vector<int>& productoMasVendido, const vector<vector<int>>& ventas) {
    cout << "Programa creado por Alyx Claire" << endl;
    cout << "Tabla de Resultados:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "| Producto | Total Ventas |";
    for (int j = 0; j < NUM_MESES; ++j) {
        cout << " " << NOMBRES_MESES[j] << " |";
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;

    // Imprimir datos de cada producto
    for (int i = 0; i < NUM_PRODUCTOS; ++i) {
        cout << "|    " << i + 1 << "    |     " << ventasProductos[i] << "      |";
        for (int j = 0; j < NUM_MESES; ++j) {
            cout << "    " << ventas[i][j] << "    |";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------------" << endl;

    // Imprimir totales de ventas por mes
    cout << "|   Total  |";
    for (int j = 0; j < NUM_MESES; ++j) {
        cout << "    " << ventasMeses[j] << "    |";
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;

    // Imprimir productos más vendidos por mes
    cout << "| Más Vend. |";
    for (int j = 0; j < NUM_MESES; ++j) {
        cout << "  Prod " << productoMasVendido[j] + 1 << "  |";
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
}

int main() {
    vector<vector<int>> ventas(NUM_PRODUCTOS, vector<int>(NUM_MESES, 0));

    // Simulación de datos de ventas
    for (int i = 0; i < NUM_PRODUCTOS; ++i) {
        for (int j = 0; j < NUM_MESES; ++j) {
            ventas[i][j] = rand() % 100; // Número aleatorio entre 0 y 99
        }
    }

    vector<int> ventasProductos(NUM_PRODUCTOS);
    vector<int> ventasMeses(NUM_MESES);
    vector<int> productoMasVendido(NUM_MESES);

    calcularVentasProductos(ventas, ventasProductos);
    calcularVentasMeses(ventas, ventasMeses);
    productoMasVendidoPorMes(ventas, productoMasVendido);

    imprimirResultados(ventasProductos, ventasMeses, productoMasVendido, ventas);

    return 0;
}