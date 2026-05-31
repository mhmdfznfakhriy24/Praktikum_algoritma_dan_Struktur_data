#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Bubble Sort manual (tanpa library)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search manual (tanpa library)
int binarySearch(int arr[], int n, int target, int excludeIndex) {
    int kiri = 0, kanan = n - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (arr[tengah] == target && tengah != excludeIndex) {
            return tengah;
        } else if (arr[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n >> x;

    // Generate array random 1-25
    srand(time(NULL));
    int arr[n];
    cout << "Array yang di-generate: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 25 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort dulu sebelum binary search
    bubbleSort(arr, n);
    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Hitung pasangan
    int count = 0;
    for (int i = 0; i < n; i++) {
        int selisih = x - arr[i];
        int hasil = binarySearch(arr, n, selisih, i);
        if (hasil != -1 && hasil > i) {
            count++;
            cout << "Pasangan: " << arr[i] << " + " << arr[hasil] << " = " << x << endl;
        }
    }

    cout << "\nTotal pasangan: " << count << endl;

    return 0;
}