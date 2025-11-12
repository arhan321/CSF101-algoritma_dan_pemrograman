#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        cout << "Partition pada indeks " << low << " hingga " << high << ": ";
        for (int i = low; i <= high; ++i)
            cout << arr[i] << " ";
        cout << endl;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    cout << "Array awal: ";
    printArray(arr);

    cout << "\nProses Quick Sort:\n";
    quickSort(arr, 0, n - 1);

    cout << "\nArray setelah sorting: ";
    printArray(arr);

    return 0;
}
