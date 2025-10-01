#include <iostream>
using namespace std;

int main() {
    int arr[7] = {2, 5, 7, 12, 18, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 18; // Angka yang akan dicari
    int result = -1;

    // Proses pencarian Linear Search
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            result = i;
            break;
        }
    }

    // Output hasil pencarian
    if (result != -1) {
        cout << "Angka ditemukan di indeks ke-" << result << endl;
    } else {
        cout << "Angka tidak ditemukan" << endl;
    }

    return 0;
}
