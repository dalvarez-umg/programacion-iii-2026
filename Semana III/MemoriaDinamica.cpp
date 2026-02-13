#include <iostream>
using namespace std;

int main() {
    int* p = new int(15);
    cout << p << endl;  //¿qué imprime?
    cout << *p << endl;  //¿qué imprime?
    cout << &p << endl;  //¿qué imprime?
    return 0;
}