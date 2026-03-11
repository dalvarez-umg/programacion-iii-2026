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

    while(contador < n) {

        cout << "Ingrese numero: ";
        cin >> valor;

        Nodo* nuevo = new Nodo;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;

        if(head == NULL) {
            head = nuevo;
        } 
        else {

            Nodo* actual = head;

            while(actual->siguiente != NULL) {
                actual = actual->siguiente;
            }

            actual->siguiente = nuevo;
        }

        contador++;
    }

    cout << "\nElementos de la lista:\n";

    Nodo* recorrido = head;

    while(recorrido != NULL) {
        cout << recorrido->dato << " ";
        recorrido = recorrido->siguiente;
    }

    cout << endl;

    return 0;
}