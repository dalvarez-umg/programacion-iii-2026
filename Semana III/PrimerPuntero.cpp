#include <iostream>
using namespace std;

int main() {
    int x = 5;        // Variable normal
    int* p = &x;      // Puntero que guarda la dirección de x

    cout << "Valor de x: " << x << endl;
    cout << "Direccion de x: " << &x << endl;

    cout << "Valor de p (direccion que almacena): " << p << endl;
    cout << "Valor al que apunta p (*p): " << *p << endl;
    return 0;
}