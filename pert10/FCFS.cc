#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    int bt[n], wt[n], tat[n];
    string proc[n];

    // Input proses
    for (int i = 0; i < n; i++) {
        cout << "Nama proses ke-" << i + 1 << ": ";
        cin >> proc[i];
        cout << "Burst time: ";
        cin >> bt[i];
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
    cout << "\n=== FCFS Scheduling ===\n";
    cout << "Proses\tBT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << proc[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}
