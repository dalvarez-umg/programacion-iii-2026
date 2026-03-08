#include <iostream>
using namespace std;

struct Estudiante {
    int id;
    string nombre;
    int edad;
};

struct Nodo {
    Estudiante data;
    Nodo* siguiente;
};
int main () {
    Nodo* primero = new Nodo;
    primero->data.id = 1;
    primero->data.nombre = "Ana";
    primero->data.edad = 20;

    primero->siguiente = nullptr;

    Nodo* segundo = new Nodo;
    segundo->data.id = 2;
    segundo->data.nombre = "Luis";
    segundo->data.edad = 21;
    segundo->siguiente = nullptr;

    primero->siguiente = segundo;

    Nodo* tercero = new Nodo;
    tercero->data.id = 3;
    tercero->data.nombre = "Maria";
    tercero->data.edad = 22;
    tercero->siguiente = nullptr;

    segundo->siguiente = tercero;

    Nodo* actual = primero;
    while (actual != nullptr) {
        cout << actual->data.nombre << endl;
        actual = actual->siguiente;
    }

    actual = primero;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }

    primero = nullptr;

    return 0;
}