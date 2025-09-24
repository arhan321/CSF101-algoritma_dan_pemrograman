#include <iostream>
#include <string>
using namespace std;

int main() {
    int angka1, angka2, hasil;
    string operasi;

    cout << "Masukkan angka pertama: ";
    cin >> angka1;

    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "Masukkan operasi (contoh: tambah): ";
    cin >> operasi;

    if (operasi == "tambah") {
        hasil = angka1 + angka2;
        cout << "Hasil penjumlahan: " << hasil << endl;
    } else {
        cout << "Pesan Error: Operasi tidak dikenali" << endl;
    }

    return 0;
}
