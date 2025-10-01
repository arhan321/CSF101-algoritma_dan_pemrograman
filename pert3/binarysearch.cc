#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 7;       // elemen yang dicari
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            cout << "Elemen ditemukan di indeks: " << mid << endl;
            return 0;
        }

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << "Elemen tidak ditemukan" << endl;

    return 0;
}
