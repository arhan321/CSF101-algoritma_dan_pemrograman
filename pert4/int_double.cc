#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    int c;
    double hasil;

    cout << "=============================================" << endl;
    cout << "Ini adalah program operasi aritmatika" << endl;
    cout << "=============================================" << endl;

    cout << "Silahkan pilih mau operasi apa :" << endl;
    cout << "1. Pertambahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Pembagian" << endl;

    cout << "Masukkan pilihan : ";
    cin >> a;

    if (a == 1) {
        cout << "Masukkan angka pertama : ";
        cin >> b;
        cout << "Masukkan angka kedua : ";
        cin >> c;
        hasil = b + c;
        cout << "Hasilnya adalah : " << hasil << endl;
    } 
    else if (a == 2) {
        cout << "Masukkan angka pertama : ";
        cin >> b;
        cout << "Masukkan angka kedua : ";
        cin >> c;
        hasil = b - c;
        cout << "Hasilnya adalah : " << hasil << endl;
    } 
    else if (a == 3) {
        cout << "Masukkan angka pertama : ";
        cin >> b;
        cout << "Masukkan angka kedua : ";
        cin >> c;
        hasil = b * c;
        cout << "Hasilnya adalah : " << hasil << endl;
    } 
    else if (a == 4) {
        cout << "Masukkan angka pertama : ";
        cin >> b;
        cout << "Masukkan angka kedua : ";
        cin >> c;
        hasil = static_cast<double>(b) / c; // konversi agar hasil pecahan tidak hilang
        cout << "Hasilnya adalah : " << hasil << endl;
    } 
    else {
        cout << "Pilihan tidak ada" << endl;
    }

    cout << "=============================================" << endl;
    cout << "Terima kasih sudah menggunakan program ini" << endl;
    cout << "=============================================" << endl;

    return 0;
}
