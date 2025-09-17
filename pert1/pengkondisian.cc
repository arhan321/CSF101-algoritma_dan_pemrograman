#include <iostream>
using namespace std;

int main() {
    int nilai;

    cout << "Masukkan nilai ujian: ";
    cin >> nilai;

    if (nilai >= 60) {
        cout << "Selamat, Anda Lulus!" << endl;
    } else {
        cout << "Maaf, Anda Tidak Lulus." << endl;
    }

    return 0;
}
