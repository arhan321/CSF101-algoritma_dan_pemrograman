#include <iostream>
using namespace std;

// secara ascending
int main() {
    int arr[7] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 3;  // elemen yang akan dicari

    int i = 0;

    // proses pencarian
    while (i < size && arr[i] != x) {
        i++;
    }

    // hasil pencarian
    if (i < size) {
        cout << "Elemen ditemukan di indeks: " << i << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}
