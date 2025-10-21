#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    char inputLagi;
    do {
        string nama, alamat, kontak;

        cout << "===============================================================" << endl;
        cout << "Struktur data" << endl;
        cout << "===============================================================" << endl;
        cout << "Program sederhana untuk menyimpan data di dalam teks" << endl;
        cout << "===============================================================" << endl;

        cout << "Masukkan nama   : ";
        getline(cin, nama);

        cout << "Masukkan alamat : ";
        getline(cin, alamat);

        cout << "Masukkan kontak : ";
        getline(cin, kontak);

        ofstream file("data.txt", ios::app); // mode append agar data baru ditambahkan ke file

        if (file.is_open()) {
            file << "Nama   : " << nama << endl;
            file << "Alamat : " << alamat << endl;
            file << "Kontak : " << kontak << endl;
            file << "---------------------------------------------" << endl;
            file.close();
            cout << "Data berhasil disimpan ke dalam file." << endl;
        } else {
            cout << "Gagal membuka file untuk penulisan." << endl;
        }

        cout << "Apakah Anda ingin memasukkan data lagi? (y/n): ";
        cin >> inputLagi;
        cin.ignore(); // membersihkan buffer sebelum input berikutnya

    } while (inputLagi == 'y' || inputLagi == 'Y');

    cout << "Program selesai." << endl;
    return 0;
}
