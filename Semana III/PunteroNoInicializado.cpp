#include <iostream>
using namespace std;

int main() {
    int* p;
    *p = 10;

    cout << "Valor de p (direccion que almacena): " << p << endl;
    cout << "Valor al que apunta p (*p): " << *p << endl;
    return 0;
}