#include <iostream>
#include <fstream>
#include <cstring>

struct persona {
    char apellido[15];
    char nombre[15];
    char edad[4];
};

// Función para inicializar el archivo con 100 registros vacíos
void inicializarArchivo(const char* nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::binary);
    persona personaVacia = {"sin-asignar", "", "0"};
    for (int i = 0; i < 100; ++i) {
        archivo.write(reinterpret_cast<const char*>(&personaVacia), sizeof(persona));
    }
    archivo.close();
}

// Función para introducir 10 apellidos, nombres y edades
void introducirDatos(const char* nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) {
        std::cerr << "Error al escribir el archivo." << std::endl;
        return;
    }

    for (int i = 0; i < 10; ++i) {
        persona p;
        std::cout << "Introduce apellido, nombre y edad para la persona " << i + 1 << ":" << std::endl;
        std::cin >> p.apellido >> p.nombre >> p.edad;

        archivo.seekp(i * sizeof(persona), std::ios::beg);
        archivo.write(reinterpret_cast<const char*>(&p), sizeof(persona));
    }

    archivo.close();
}

// Función para actualizar un registro
void actualizarRegistro(const char* nombreArchivo, int indice) {
    std::fstream archivo(nombreArchivo, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return;
    }

    archivo.seekg(indice * sizeof(persona), std::ios::beg);
    persona p;
    archivo.read(reinterpret_cast<char*>(&p), sizeof(persona));

    if (strcmp(p.apellido, "sin-asignar") == 0) {
        std::cout << "No hay información en el registro." << std::endl;
    } else {
        std::cout << "Introduce nuevo apellido, nombre y edad:" << std::endl;
        std::cin >> p.apellido >> p.nombre >> p.edad;

        archivo.seekp(indice * sizeof(persona), std::ios::beg);
        archivo.write(reinterpret_cast<const char*>(&p), sizeof(persona));
    }

    archivo.close();
}

// Función para eliminar un registro
void eliminarRegistro(const char* nombreArchivo, int indice) {
    std::fstream archivo(nombreArchivo, std::ios::binary | std::ios::in | std::ios::out);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para eliminar." << std::endl;
        return;
    }

    persona p = {"sin-asignar", "", "0"};
    archivo.seekp(indice * sizeof(persona), std::ios::beg);
    archivo.write(reinterpret_cast<const char*>(&p), sizeof(persona));

    archivo.close();
}

int main() {
    const char* nombreArchivo = "nomedad.dat";

    inicializarArchivo(nombreArchivo);
    introducirDatos(nombreArchivo);

    int opcion, indice;
    do {
        std::cout << "Seleccione una opción: 1) Actualizar Registro 2) Eliminar Registro 3) Salir: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Introduce el índice del registro a actualizar (0-99): ";
                std::cin >> indice;
                actualizarRegistro(nombreArchivo, indice);
                break;
            case 2:
                std::cout << "Introduce el índice del registro a eliminar (0-99): ";
                std::cin >> indice;
                eliminarRegistro(nombreArchivo, indice);
                break;
            case 3:
                std::cout << "Hey hey hey alejense de mi almacén..." << std::endl;
                break;
            default:
                std::cout << "Opción más inválida que tus sueños." << std::endl;
        }
    } while (opcion != 3);

    return 0;
}