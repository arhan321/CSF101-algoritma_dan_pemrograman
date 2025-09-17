#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama;
    int angka;

    cout << "Masukkan nama Anda: ";
    getline(cin, nama); 

    
    cout << "Masukkan sebuah angka: ";
    cin >> angka;

    cout << "\nHalo, " << nama << "!" << endl;
    cout << "Anda memasukkan angka: " << angka << endl;
    cout << "Hasil perhitungan kuadrat dari angka tersebut: " << angka * angka << endl;

    return 0;
}
