#include <iostream>
#include <string>
using namespace std;

int main() {
    // Dummy akun bawaan (default)
    string username = "admin";
    string password = "12345";

    // Variabel input dari user
    string inputUser, inputPass;
    int pilihan;

    cout << "===== SISTEM LOGIN & REGISTER DUMMY =====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Pilih menu (1/2): ";
    cin >> pilihan;

    if (pilihan == 1) {
        cout << "\n=== REGISTER ===" << endl;
        cout << "Masukkan Username baru: ";
        cin >> username;  
        cout << "Masukkan Password baru: ";
        cin >> password;   

        cout << "\nRegistrasi berhasil!" << endl;
        cout << "Akun baru telah dibuat dengan username: " << username << endl;
    }
    else if (pilihan == 2) {
        // Proses Login
        cout << "\n=== LOGIN ===" << endl;
        cout << "Masukkan Username: ";
        cin >> inputUser;
        cout << "Masukkan Password: ";
        cin >> inputPass;

        // Pengecekan login
        if (inputUser == username && inputPass == password) {
            cout << "\nLogin berhasil! Selamat datang, " << username << endl;
        } else {
            cout << "\nLogin gagal! Username atau Password salah." << endl;
        }
    }
    else {
        cout << "\nKeluar dari sistem." << endl;
    }

    return 0;
}
