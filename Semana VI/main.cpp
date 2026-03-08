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
    cout << "Cuantos nodos desea crear? ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Ingrese valor: ";
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
    }
    cout << "\nLista creada:\n";

    Nodo* temp = head;
    while(temp != NULL) {
        cout << temp->dato << " -> ";
        temp = temp->siguiente;
    }
    cout << "NULL";

    return 0;
}