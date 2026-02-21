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

int main() {
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

    cout << "primero: " << primero << endl;
    cout << "segundo: " << segundo << endl;

    primero->siguiente = segundo;

    Nodo* tercero = new Nodo;
    tercero->data.id = 3;
    tercero->data.nombre = "Maria";
    tercero->data.edad = 19;
    tercero->siguiente = nullptr;

    segundo->siguiente = tercero;

    cout << primero->data.nombre << endl; // Ana
    cout << primero->siguiente->data.nombre << endl; // Luis
    cout << primero->siguiente->siguiente->data.nombre << endl; // Maria

    Nodo* actual = primero;
    while (actual != nullptr) {
        cout << "ID: " << actual->data.id
             << " Nombre: " << actual->data.nombre
             << " Edad: " << actual->data.edad << endl;

        actual = actual->siguiente;
    }

    //Liberar memoria

    actual = primero;

    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    primero = nullptr;

    return 0;
}