#include <iostream>
#include <algorithm>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
    int altura;

    Nodo(int valor) {
        dato = valor;
        izquierda = nullptr;
        derecha = nullptr;
        altura = 1;
    }
};

int obtenerAltura(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->altura;
}

int obtenerBalance(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
}

Nodo* rotarDerecha(Nodo* y) {
    Nodo* x = y->izquierda;
    Nodo* temp = x->derecha;

    x->derecha = y;
    y->izquierda = temp;

    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

    return x;
}

Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->derecha;
    Nodo* temp = y->izquierda;

    y->izquierda = x;
    x->derecha = temp;

    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

    return y;
}

Nodo* insertar(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return new Nodo(valor);
    }

    if (valor < nodo->dato) {
        nodo->izquierda = insertar(nodo->izquierda, valor);
    } else if (valor > nodo->dato) {
        nodo->derecha = insertar(nodo->derecha, valor);
    } else {
        return nodo;
    }

    nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

    int balance = obtenerBalance(nodo);

    // Caso LL
    if (balance > 1 && valor < nodo->izquierda->dato) {
        return rotarDerecha(nodo);
    }

    // Caso RR
    if (balance < -1 && valor > nodo->derecha->dato) {
        return rotarIzquierda(nodo);
    }

    // Caso LR
    if (balance > 1 && valor > nodo->izquierda->dato) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }

    // Caso RL
    if (balance < -1 && valor < nodo->derecha->dato) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void inOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        inOrden(raiz->izquierda);
        cout << raiz->dato << " ";
        inOrden(raiz->derecha);
    }
}

void preOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->dato << " ";
        preOrden(raiz->izquierda);
        preOrden(raiz->derecha);
    }
}

void postOrden(Nodo* raiz) {
    if (raiz != nullptr) {
        postOrden(raiz->izquierda);
        postOrden(raiz->derecha);
        cout << raiz->dato << " ";
    }
}

int main() {
    Nodo* raiz = nullptr;

    int valores[] = {30, 20, 10, 40, 50, 25};
    int cantidad = 6;

    for (int i = 0; i < cantidad; i++) {
        raiz = insertar(raiz, valores[i]);
    }

    cout << "Recorrido InOrden: ";
    inOrden(raiz);

    cout << "\nRecorrido PreOrden: ";
    preOrden(raiz);

    cout << "\nPostOrden: ";
    postOrden(raiz);

    return 0;
}