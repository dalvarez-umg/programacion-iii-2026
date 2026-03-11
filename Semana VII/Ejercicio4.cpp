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

    int numeroBuscar;

    cout << "\nIngrese numero a buscar: ";
    cin >> numeroBuscar;

    Nodo* recorrido = head;
    bool encontrado = false;

    while(recorrido != NULL) {

        if(recorrido->dato == numeroBuscar) {
            encontrado = true;
            break;
        }

        recorrido = recorrido->siguiente;
    }

    if(encontrado) {
        cout << "\nEl numero existe en la lista\n";
    } else {
        cout << "\nNo se encontro el numero\n";
    }

    return 0;
}