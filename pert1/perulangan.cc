#include <iostream>
using namespace std;

int main() {
    // 1. Perulangan For (jumlah pasti)
    cout << "Perulangan For:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Perulangan ke-" << i << endl;
    }
    cout << endl;

    // 2. Perulangan While (cek kondisi dulu baru jalan)
    cout << "Perulangan While:" << endl;
    int j = 1;
    while (j <= 5) {
        cout << "Perulangan ke-" << j << endl;
        j++;
    }
    cout << endl;

    // 3. Perulangan Do-While (jalan dulu, cek kondisi belakangan)
    cout << "Perulangan Do-While:" << endl;
    int k = 1;
    do {
        cout << "Perulangan ke-" << k << endl;
        k++;
    } while (k <= 5);

    return 0;
}
