#include <iostream>
using namespace std;

int main() {
    /*
     * Se reserva memoria en el stack
     * x contiene 5
     */
    int x = 5;        // Variable normal
    /*
     * &x obtiene la dirección de memoria de x
     * p almacena esa dirección
     * p NO almacena 5
     * p almacena la dirección de memoria 0xec75dff984
     */
    int* p = &x;      // Puntero que guarda la dirección de x

    cout << "Valor de x: " << x << endl;
    cout << "Direccion de x: " << &x << endl;

    cout << "Valor de p (direccion que almacena): " << p << endl;
    cout << "Valor al que apunta p (*p): " << *p << endl;

    x = 20;
    cout << "---- DESPUES DE *p = 20 ----" << endl;
    cout << "Valor de x: " << x << endl;
    cout << "Valor de *p: " << *p << endl;

    return 0;
}