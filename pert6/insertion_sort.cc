#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "Langkah " << i << " : ";
        for (int k = 0; k < n; ++k)
            cout << arr[k] << " ";
        cout << endl;
    }
}

int main() {
    int arr[] = {54, 33, 13, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array awal: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Proses Insertion Sort:\n";
    insertionSort(arr, n);

    cout << "\nArray setelah sorting: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
