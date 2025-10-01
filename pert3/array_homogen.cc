#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    cout << "Contoh Array dengan tipe data yang sama : ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
        if (i < 4) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
