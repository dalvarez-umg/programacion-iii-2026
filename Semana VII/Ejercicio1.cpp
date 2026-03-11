#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

int main() {

    Nodo* head = NULL;
    Nodo* actual = NULL;

    int n, valor;
    int contador = 0;

    cout << "Cuantos numeros desea ingresar? ";
    cin >> n;

    while(contador < n) {

        cout << "Ingrese numero: ";
        cin >> valor;

        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        if(head == NULL) {
            head = nuevo;
            actual = nuevo;
        } else {
            actual->siguiente = nuevo;
            actual = nuevo;
        }

        contador++;
    }

    cout << "\nElementos almacenados en la lista:\n";

    Nodo* recorrido = head;

    while(recorrido != NULL) {
        cout << recorrido->dato << endl;
        recorrido = recorrido->siguiente;
    }

    return 0;
}