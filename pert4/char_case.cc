#include <iostream>
using namespace std;

int main() {
    // program mengkonversi angka ke ASCII
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;

    if (angka < 32 || angka > 126) {
        cout << "Angka yang dimasukkan tidak valid" << endl;
    }
    else if (angka == 32) {
        cout << "Hasil konversi: spasi" << endl;
    }
    else if (angka == 127) {
        cout << "Hasil konversi: delete" << endl;
    }
    else {
        char konversi = angka;
        cout << "Hasil konversi: " << konversi << endl;
    }

    return 0;
}
