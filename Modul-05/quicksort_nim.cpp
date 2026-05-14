#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot adalah elemen terakhir
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // Jika elemen lebih kecil atau sama dengan pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Tempatkan pivot di posisi yang tepat
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Urutkan bagian kiri
        quickSort(arr, pi + 1, high); // Urutkan bagian kanan
    }
}

int main() {
    int nim[] = {2, 5, 1, 0, 8, 1, 7, 3, 1, 0, 0, 1, 7};
    int n = 13;

    cout << "==============================" << endl;
    cout << "         QUICK SORT           " << endl;
    cout << "==============================" << endl;

    cout << "\nData Sebelum Sorting: ";
    for (int i = 0; i < n; i++) cout << nim[i] << " ";
    cout << endl;

    quickSort(nim, 0, n - 1);

    cout << "Data Sesudah Sorting: ";
    for (int i = 0; i < n; i++) cout << nim[i] << " ";
    cout << endl;

    return 0;
}