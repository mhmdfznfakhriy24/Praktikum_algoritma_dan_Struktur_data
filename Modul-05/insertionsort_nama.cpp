#include <iostream>
#include <string>
using namespace std;

void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;

        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Sisipkan key ke posisi yang tepat
        arr[j + 1] = key;
    }
}

int main() {
    string nama[] = {"Muhammad", "Fauzan", "Fakhriy", "Hartono"};
    int n = 4;

    cout << "==============================" << endl;
    cout << "       INSERTION SORT         " << endl;
    cout << "==============================" << endl;

    cout << "\nData Sebelum Sorting: ";
    for (int i = 0; i < n; i++) cout << nama[i] << " ";
    cout << endl;

    insertionSort(nama, n);

    cout << "Data Sesudah Sorting: ";
    for (int i = 0; i < n; i++) cout << nama[i] << " ";
    cout << endl;

    return 0;
}