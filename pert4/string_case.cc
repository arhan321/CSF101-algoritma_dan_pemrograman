#include <iostream>
#include <string>
using namespace std;

int main() {
    string Nama;
    string NIM;
    string fakultas;
    string jurusan;

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
    cout << "Terimakasih" << endl;
    cout << "" << endl;
    cout << "==============================================" << endl;

    cout << "\nData Mahasiswa:" << endl;
    cout << "Nama     : " << Nama << endl;
    cout << "NIM      : " << NIM << endl;
    cout << "Fakultas : " << fakultas << endl;
    cout << "Jurusan  : " << jurusan << endl;

    return 0;
}
