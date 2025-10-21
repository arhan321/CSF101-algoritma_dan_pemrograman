#include <iostream>
#include <string>
using namespace std;

enum MataKuliah { Struktur_data, Kalkulus1, Orakom, Organisasi_management, DSI };

struct Dosen {
    string nama_dosen;
    int NIK_dosen;
    string alamat_dosen;
    MataKuliah mengajar;
};

void isiDataDosen(Dosen &dosen) {
    cout << "Masukkan Nama Dosen: ";
    getline(cin, dosen.nama_dosen);

    cout << "Masukkan NIK Dosen: ";
    cin >> dosen.NIK_dosen;

    cin.ignore();
    cout << "Masukkan Alamat Dosen: ";
    getline(cin, dosen.alamat_dosen);

    cout << "Pilih Mata Kuliah yang Diajarkan (0: Struktur_data, 1: Kalkulus1, 2: Orakom, 3: Organisasi_management, 4: DSI): ";
    int pilihan;
    cin >> pilihan;
    dosen.mengajar = static_cast<MataKuliah>(pilihan);

    cin.ignore();
}

void tampilkanDataDosen(const Dosen &dosen) {
    string mataKuliah[] = {"Struktur_data", "Kalkulus1", "Orakom", "Organisasi_management", "DSI"};

    cout << "Nama Dosen       : " << dosen.nama_dosen << endl;
    cout << "NIK Dosen        : " << dosen.NIK_dosen << endl;
    cout << "Alamat Dosen     : " << dosen.alamat_dosen << endl;
    cout << "Mata Kuliah yang Diajarkan : " << mataKuliah[dosen.mengajar] << endl;
}

int main() {
    char lanjut;
    do {
        Dosen dosen;
        cout << "" << endl;
        cout << "===================== Mengisi data Dosen =====================" << endl;
        isiDataDosen(dosen);

        cout << "" << endl;
        cout << "===================== Data dosen yang sudah diisi : =====================" << endl;
        tampilkanDataDosen(dosen);

        cout << "--------------------------------------------------------------" << endl;
        cout << "Ingin memasukkan data dosen lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore();

    } while (lanjut == 'y' || lanjut == 'Y');

    cout << "Program selesai. Terima kasih!" << endl;

    return 0;
}
