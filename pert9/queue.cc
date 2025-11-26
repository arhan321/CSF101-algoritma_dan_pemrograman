#include <iostream>
using namespace std;

#define MAX 5   // kapasitas maksimal queue

struct Queue {
    int data[MAX];
    int front;
    int rear;
    int count;
};

// Inisialisasi queue
void init(Queue &q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

// Mengecek apakah queue penuh
bool isFull(Queue q) {
    return q.count == MAX;
}

// Mengecek apakah queue kosong
bool isEmpty(Queue q) {
    return q.count == 0;
}

// Menambahkan elemen ke queue (enqueue)
void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak bisa enqueue." << endl;
        return;
    }

    q.rear = (q.rear + 1) % MAX;  
    q.data[q.rear] = value;
    q.count++;

    cout << "Enqueue: " << value << " berhasil dimasukkan!" << endl;
}

// Menghapus elemen dari queue (dequeue)
int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong! Tidak bisa dequeue." << endl;
        return -1;
    }

    int value = q.data[q.front];
    q.front = (q.front + 1) % MAX;
    q.count--;

    cout << "Dequeue: " << value << " berhasil dihapus!" << endl;
    return value;
}

// Melihat elemen terdepan
int frontValue(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }
    return q.data[q.front];
}

// Menampilkan isi queue
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    cout << "Isi Queue: ";
    int idx = q.front;

    for (int i = 0; i < q.count; i++) {
        cout << q.data[idx] << " ";
        idx = (idx + 1) % MAX;
    }

    cout << endl;
}

// MAIN PROGRAM DENGAN MENU
int main() {
    Queue q;
    init(q);

    int pilihan, nilai;

    do {
        cout << "\n=== PROGRAM QUEUE (ANTRIAN) ===" << endl;
        cout << "1. Enqueue (Tambah Data)" << endl;
        cout << "2. Dequeue (Hapus Data)" << endl;
        cout << "3. Lihat Elemen Depan" << endl;
        cout << "4. Tampilkan Isi Queue" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueue(q, nilai);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                nilai = frontValue(q);
                if (nilai != -1)
                    cout << "Elemen depan: " << nilai << endl;
                break;

            case 4:
                display(q);
                break;

            case 5:
                cout << "Program selesai. Terima kasih." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}
