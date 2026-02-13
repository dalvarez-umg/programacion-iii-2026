#include <iostream>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};
    cout << arr[5] << endl;  // Undefined Behavior
    return 0;
}