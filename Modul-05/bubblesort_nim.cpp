#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {

        bool swapped = false;

        // Setiap putaran, elemen terbesar akan naik ke akhir
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar jika elemen kiri lebih besar dari kanan
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // Jika tidak ada pertukaran, array sudah terurut
        if (!swapped) break;
    }
}

int main() {
    int nim[] = {2, 5, 1, 0, 8, 1, 7, 3, 1, 0, 0, 1, 7};
    int n = 13;

    cout << "==============================" << endl;
    cout << "         BUBBLE SORT          " << endl;
    cout << "==============================" << endl;

    cout << "\nData Sebelum Sorting: ";
    for (int i = 0; i < n; i++) cout << nim[i] << " ";
    cout << endl;

    bubbleSort(nim, n);

    cout << "Data Sesudah Sorting: ";
    for (int i = 0; i < n; i++) cout << nim[i] << " ";
    cout << endl;

    return 0;
}