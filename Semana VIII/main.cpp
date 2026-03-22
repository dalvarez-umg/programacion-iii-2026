#include <iostream>
using namespace std;

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Puntero al tope de la pila
Nodo* tope = NULL;

// PUSH: insertar elemento en la pila
void push(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;

    cout << "Elemento " << valor << " insertado en la pila." << endl;
}

// POP: eliminar elemento del tope
void pop() {
    if (tope == NULL) {
        cout << "La pila esta vacia. No se puede eliminar." << endl;
        return;
    }

    Nodo* temp = tope;
    cout << "Elemento eliminado: " << temp->dato << endl;

    tope = tope->siguiente;
    delete temp;
}

// PEEK: ver el elemento en el tope
void peek() {
    if (tope == NULL) {
        cout << "La pila esta vacia." << endl;
    } else {
        cout << "Elemento en el tope: " << tope->dato << endl;
    }
}

// Mostrar toda la pila
void mostrar() {
    if (tope == NULL) {
        cout << "La pila esta vacia." << endl;
        return;
    }

    Nodo* actual = tope;
    cout << "Contenido de la pila (tope -> base): ";

    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }

    cout << "NULL" << endl;
}

// Programa principal
int main() {
    int opcion, valor;

    do {
        cout << "\n===== MENU PILA =====" << endl;
        cout << "1. Push (Insertar)" << endl;
        cout << "2. Pop (Eliminar)" << endl;
        cout << "3. Peek (Ver tope)" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                push(valor);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                mostrar();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 5);

    return 0;
}