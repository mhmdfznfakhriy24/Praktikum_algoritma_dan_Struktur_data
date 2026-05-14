#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {

        // Anggap elemen ke-i sebagai elemen terkecil
        int minIndex = i;

        // Cari elemen terkecil di sisa array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Tukar elemen terkecil dengan elemen di posisi i
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int nim[] = {2, 5, 1, 0, 8, 1, 7, 3, 1, 0, 0, 1, 7};
    int n = 13;

    cout << "==============================" << endl;
    cout << "       SELECTION SORT         " << endl;
    cout << "==============================" << endl;

    cout << "\nData Sebelum Sorting: ";
    for (int i = 0; i < n; i++) cout << nim[i] << " ";
    cout << endl;

    selectionSort(nim, n);

    cout << "Data Sesudah Sorting: ";
    for (int i = 0; i < n; i++) cout << nim[i] << " ";
    cout << endl;

    return 0;
}