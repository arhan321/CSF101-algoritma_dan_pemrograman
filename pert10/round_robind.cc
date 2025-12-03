#include <iostream>
using namespace std;

int main() {
    int n, quantum;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    string proc[n];
    int bt[n], rt[n], wt[n], tat[n];

    // Input proses
    for (int i = 0; i < n; i++) {
        cout << "Nama proses ke-" << i + 1 << ": ";
        cin >> proc[i];
        cout << "Burst time: ";
        cin >> bt[i];
        rt[i] = bt[i];    // rt = remaining time
    }

    cout << "Masukkan quantum: ";
    cin >> quantum;

    int time = 0;

    // Round Robin
    bool done;
    do {
        done = true;

        for (int i = 0; i < n; i++) {

            // Jika masih ada proses yang belum selesai
            if (rt[i] > 0) {
                done = false;

                if (rt[i] > quantum) {
                    time += quantum;
                    rt[i] -= quantum;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }

    } while (!done);

    // Hitung Turnaround Time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    // Tampilkan hasil
    cout << "\n=== ROUND ROBIN SCHEDULING ===\n";
    cout << "Proses\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << proc[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}
