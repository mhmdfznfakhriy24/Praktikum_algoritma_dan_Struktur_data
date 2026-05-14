#include <iostream>
#include <string>
using namespace std;

void merge(string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string L[n1], R[n2];

    // Salin data ke array sementara
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Gabungkan kembali dengan urutan yang benar
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen L jika ada
    while (i < n1) { arr[k] = L[i]; i++; k++; }

    // Salin sisa elemen R jika ada
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort(string arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // Urutkan bagian kiri
        mergeSort(arr, mid + 1, right);  // Urutkan bagian kanan
        merge(arr, left, mid, right);    // Gabungkan keduanya
    }
}

int main() {
    string nama[] = {"Muhammad", "Fauzan", "Fakhriy", "Hartono"};
    int n = 4;

    cout << "==============================" << endl;
    cout << "         MERGE SORT           " << endl;
    cout << "==============================" << endl;

    cout << "\nData Sebelum Sorting: ";
    for (int i = 0; i < n; i++) cout << nama[i] << " ";
    cout << endl;

    mergeSort(nama, 0, n - 1);

    cout << "Data Sesudah Sorting: ";
    for (int i = 0; i < n; i++) cout << nama[i] << " ";
    cout << endl;

    return 0;
}