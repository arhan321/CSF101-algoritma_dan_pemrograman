#include <iostream>
using namespace std;

int main() {
    enum hari {
        senin,
        selasa,
        rabu,
        kamis,
        jumat,
        sabtu,
        minggu
    };

    hari hari_ini = senin;

    cout << "Tipe data enum (enumeration)" << endl;
    cout << "Hari ini adalah hari ke-" << hari_ini + 1 << endl;

    return 0;
}
