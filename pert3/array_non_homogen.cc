#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    string Nama[5] = {"Arhan", "RizkiWahyu", "Fajri", "Noval", "athar"};

    cout << "=============================================" << endl;
    cout << "Array dengan tipe data berbeda : " << endl;

    cout << "\nMenampilkan tipe data int" << endl;
    cout << "Elemen-elemen array: ";
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << ", ";
    }
    cout << endl;

    cout << "=============================================" << endl;
    cout << "\nMenampilkan tipe data string" << endl;
    cout << "Elemen-elemen array: ";
    for (int i = 0; i < 5; i++) {
        cout << Nama[i] << ", ";
    }
    cout << endl;

    return 0;
}
