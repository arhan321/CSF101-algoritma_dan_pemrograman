#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    string proc[n];
    int bt[n], wt[n], tat[n];

    // Input proses
    for (int i = 0; i < n; i++) {
        cout << "Nama proses ke-" << i + 1 << ": ";
        cin >> proc[i];
        cout << "Burst time: ";
        cin >> bt[i];
    }

    // Sorting berdasarkan burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                swap(bt[i], bt[j]);
                swap(proc[i], proc[j]);
            }
        }
    }

    // Hitung waiting time
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Hitung turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Tampilkan hasil
    cout << "\n=== SJF Non-Preemptive Scheduling ===\n";
    cout << "Proses\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << proc[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}
