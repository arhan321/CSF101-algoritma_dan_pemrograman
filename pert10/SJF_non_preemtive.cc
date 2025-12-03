#include <iostream>
#include <vector>
using namespace std;

struct Process {
    string name;
    int bt;
    int wt;
    int tat;
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);

    // Input data
    for (int i = 0; i < n; i++) {
        cout << "Nama proses ke-" << i + 1 << ": ";
        cin >> p[i].name;
        cout << "Burst time: ";
        cin >> p[i].bt;
    }

    // Sorting berdasarkan burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j].bt < p[i].bt) {
                swap(p[i], p[j]);
            }
        }
    }

    // Hitung waiting time
    p[0].wt = 0;
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    // Hitung turnaround time
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
    }

    // Tampilkan hasil tabel
    cout << "\n=== SJF Non-Preemptive Scheduling ===\n";
    cout << "Proses\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].name << "\t"
             << p[i].bt << "\t"
             << p[i].wt << "\t"
             << p[i].tat << endl;
    }

    // ============================
    //         GANTT CHART
    // ============================
    cout << "\n=== Gantt Chart ===\n";

    // Bar atas
    cout << " ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++) cout << "--";
        cout << " ";
    }
    cout << "\n|";

    // Nama proses
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt - 1; j++) cout << " ";
        cout << p[i].name;
        for (int j = 0; j < p[i].bt - 1; j++) cout << " ";
        cout << "|";
    }

    cout << "\n ";

    // Bar bawah
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++) cout << "--";
        cout << " ";
    }

    cout << "\n0";
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += p[i].bt;
        cout << "  ";
        if (time < 10) cout << " "; // biar rapi jika angka kecil
        cout << time;
    }

    cout << endl;

    return 0;
}
