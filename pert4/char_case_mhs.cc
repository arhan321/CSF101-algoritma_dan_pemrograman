#include <iostream>
#include <string>
using namespace std;

int main() {
    string Nama;
    string NIM;
    string fakultas;
    string jurusan;
    char pilihan;

    do {
        cout << "==============================================" << endl;
        cout << "Program mengisi data dan tampilkan data" << endl;
        cout << "==============================================" << endl;

        cout << "Masukkan Nama mahasiswa : ";
        getline(cin, Nama);

        cout << "Masukkan NIM mahasiswa : ";
        getline(cin, NIM);

        cout << "Masukkan fakultas mahasiswa : ";
        getline(cin, fakultas);

        cout << "Masukkan jurusan mahasiswa : ";
        getline(cin, jurusan);

        cout << "==============================================" << endl;
        cout << "Data yang diinputkan:" << endl;
        cout << "Nama     : " << Nama << endl;
        cout << "NIM      : " << NIM << endl;
        cout << "Fakultas : " << fakultas << endl;
        cout << "Jurusan  : " << jurusan << endl;
        cout << "==============================================" << endl;

        cout << "Apakah Anda ingin mengisi data lagi? (y/t): ";
        cin >> pilihan;
        cin.ignore(); // membersihkan buffer agar getline berikutnya tidak terlewati

    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "Terimakasih telah menggunakan program ini!" << endl;

    return 0;
}
