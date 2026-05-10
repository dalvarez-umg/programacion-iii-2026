#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    int id;
    string nombre;
};

struct Nodo {
    Estudiante estudiante;
    Nodo* siguiente;
};

class HashTable {
private:
    static const int SIZE = 10; // Pueden o deben ajustar este tamaño de buckets
    Nodo* tabla[SIZE];
    int totalElementos;
    int totalColisiones;

    int funcionHash(int id) {
        return id % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            tabla[i] = nullptr;
        }

        totalElementos = 0;
        totalColisiones = 0;
    }

    bool insertar(int id, string nombre) {
        int indice = funcionHash(id);

        // Validar ID duplicado
        if (buscar(id) != nullptr) {
            cout << "Error: ya existe un estudiante con ese ID.\n";
            return false;
        }

        Nodo* nuevo = new Nodo;
        nuevo->estudiante.id = id;
        nuevo->estudiante.nombre = nombre;
        nuevo->siguiente = nullptr;

        // Si ya hay algo en el bucket, hay colisión
        if (tabla[indice] != nullptr) {
            totalColisiones++;
        }

        // Insertar al inicio de la lista enlazada
        nuevo->siguiente = tabla[indice];
        tabla[indice] = nuevo;

        totalElementos++;

        cout << "Estudiante insertado correctamente en bucket " << indice << ".\n";
        return true;
    }

    Estudiante* buscar(int id) {
        int indice = funcionHash(id);
        Nodo* actual = tabla[indice];

        while (actual != nullptr) {
            if (actual->estudiante.id == id) {
                return &actual->estudiante;
            }

            actual = actual->siguiente;
        }

        return nullptr;
    }

    bool eliminar(int id) {
        int indice = funcionHash(id);
        Nodo* actual = tabla[indice];
        Nodo* anterior = nullptr;

        while (actual != nullptr) {
            if (actual->estudiante.id == id) {
                if (anterior == nullptr) {
                    tabla[indice] = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                }

                delete actual;
                totalElementos--;

                cout << "Estudiante eliminado correctamente.\n";
                return true;
            }

            anterior = actual;
            actual = actual->siguiente;
        }

        cout << "No se encontro estudiante con ese ID.\n";
        return false;
    }

    void mostrarTabla() {
        cout << "\n--- CONTENIDO DE LA HASH TABLE ---\n";

        for (int i = 0; i < SIZE; i++) {
            cout << "Bucket [" << i << "]: ";

            Nodo* actual = tabla[i];

            if (actual == nullptr) {
                cout << "vacio";
            }

            while (actual != nullptr) {
                cout << "(" << actual->estudiante.id << ", "
                     << actual->estudiante.nombre << ") -> ";
                actual = actual->siguiente;
            }

            cout << "NULL\n";
        }
    }

    void mostrarEstadisticas() {
        cout << "\n--- ESTADISTICAS HASH ---\n";
        cout << "Total de estudiantes: " << totalElementos << endl;
        cout << "Total de buckets: " << SIZE << endl;
        cout << "Total de colisiones: " << totalColisiones << endl;
        cout << "Factor de carga: " << calcularFactorCarga() << endl;
    }

    float calcularFactorCarga() {
        return (float) totalElementos / SIZE;
    }

    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Nodo* actual = tabla[i];

            while (actual != nullptr) {
                Nodo* temp = actual;
                actual = actual->siguiente;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable hash;
    int opcion;

    do {
        cout << "\n========== MENU HASH TABLE ==========\n";
        cout << "1. Insertar estudiante\n";
        cout << "2. Buscar estudiante por ID\n";
        cout << "3. Eliminar estudiante\n";
        cout << "4. Mostrar tabla hash\n";
        cout << "5. Mostrar estadisticas\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int id;
            string nombre;

            cout << "Ingrese ID: ";
            cin >> id;

            cin.ignore();

            cout << "Ingrese nombre: ";
            getline(cin, nombre);

            hash.insertar(id, nombre);
        }

        else if (opcion == 2) {
            int id;

            cout << "Ingrese ID a buscar: ";
            cin >> id;

            Estudiante* encontrado = hash.buscar(id);

            if (encontrado != nullptr) {
                cout << "Estudiante encontrado:\n";
                cout << "ID: " << encontrado->id << endl;
                cout << "Nombre: " << encontrado->nombre << endl;
            } else {
                cout << "Estudiante no encontrado.\n";
            }
        }

        else if (opcion == 3) {
            int id;

            cout << "Ingrese ID a eliminar: ";
            cin >> id;

            hash.eliminar(id);
        }

        else if (opcion == 4) {
            hash.mostrarTabla();
        }

        else if (opcion == 5) {
            hash.mostrarEstadisticas();
        }

        else if (opcion == 6) {
            cout << "Saliendo del programa...\n";
        }

        else {
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 6);

    return 0;
}