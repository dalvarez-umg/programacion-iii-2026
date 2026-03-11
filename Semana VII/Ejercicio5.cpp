#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {
    Nodo* head = NULL;

    int n, valor;
    int contador = 0;

    cout << "Cuantos numeros desea ingresar? ";
    cin >> n;

    while (contador < n) {
        cout << "Ingrese numero: ";
        cin >> valor;

        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        if (head == NULL) {
            head = nuevo;
        } else {
            Nodo* actual = head;

            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }

        contador++;
    }

    int numeroEliminar;
    cout << "\nIngrese numero a eliminar: ";
    cin >> numeroEliminar;

    bool encontrado = false;

    while (head != NULL && head->dato == numeroEliminar) {
        Nodo* temp = head;
        head = head->siguiente;
        delete temp;
        encontrado = true;
    }

    Nodo* actual = head;
    Nodo* anterior = NULL;

    while (actual != NULL) {
        if (actual->dato == numeroEliminar) {
            encontrado = true;
            anterior->siguiente = actual->siguiente;
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    if (encontrado) {
        cout << "\nEl numero existe en la lista y fue eliminado\n";
    } else {
        cout << "\nNo se encontro el numero\n";
    }

    cout << "\nLista resultante:\n";
    Nodo* recorrido = head;

    while (recorrido != NULL) {
        cout << recorrido->dato << " - ";
        recorrido = recorrido->siguiente;
    }

    cout << "NULL\n";

    return 0;
}