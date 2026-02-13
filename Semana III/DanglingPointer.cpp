#include <iostream>
using namespace std;

int main() {
    int* p = new int(10);
    int* q = p;
    cout << *q << endl;

    delete p;
    cout << q << endl;
    cout << *q << endl;

    return 0;
}